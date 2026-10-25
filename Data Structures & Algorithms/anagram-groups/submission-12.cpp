#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <algorithm> 
#include <cstdint>  // uint8_t, uint16_t, uint64_t
#include <cstring>  // std::memcpy

using namespace std; 

// more optimized
struct alignas(32) CharCounts { // 32 => half a CPU cacheline, 1 AVX@ regist / 4 exact uint64_t words)
    uint64_t words[4]{0,0,0,0}; // 32 bytes though first 26B isonly used 


    uint8_t* bytes() noexcept { return reinterpret_cast<uint8_t*>(words); }
    // overload 4 64bit integers 4 instuctions inttead of 26B comparisong?
    bool operator==(const CharCounts& other) const {
        return words[0] == other.words[0] &&
               words[1] == other.words[1] &&
               words[2] == other.words[2] &&
               words[3] == other.words[3];
    }
};

struct FastArrayHash {
    size_t operator()(const CharCounts& c) const noexcept {
        // Legal C++ access to 4 aligned 64-bit words (no tail needed!)
        uint64_t h = (c.words[0] * 0x9e3779b97f4a7c15ULL) ^
                     (c.words[1] * 0xbf58476d1ce4e5b9ULL) ^
                     (c.words[2] * 0x94d049bb133111ebULL) ^
                     (c.words[3] * 0xff51afd7ed558ccdULL);
        h ^= h >> 33;
        h *= 0xff51afd7ed558ccdULL;
        h ^= h >> 33;
        return static_cast<size_t>(h);
    }
};

class Solution {

    // 2. Flat Open-Addressing Hash Slot (Lives in contiguous L1/L2 cache, ZERO heap nodes)
    struct Slot {
        CharCounts key;
        int groupIdx = -1; // -1 means empty slot
    };

public: 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        const size_t n = strs.size();
        if (n == 0) return {};

        // Power-of-2 capacity >= 2 * n for < 0.5 load factor (allows fast bitwise '& mask' instead of slow '%')
        size_t cap = std::bit_ceil(n * 2 + 1);
        size_t mask = cap - 1;

        // ONE single contiguous allocation for the entire hash table!
        vector<Slot> table(cap);
        FastArrayHash hasher;

        vector<vector<string>> res;
        res.reserve(n);
        for (string& s: strs) {
            CharCounts counts {}; // zero-init, already know its 26 by the compiler alias. 
            uint8_t* b = counts.bytes();
            for (unsigned char c : s) {
                b[c - 'a']++;
            }
            
            // Linear probing lookup (replaces slow std::unordered_map::try_emplace)
            size_t idx = hasher(counts) & mask;
            while (table[idx].groupIdx != -1) {
                if (table[idx].key == counts) {
                    break; // Found existing group!
                }
                idx = (idx + 1) & mask; // Next adjacent slot in the same CPU cache line
            }

            if (table[idx].groupIdx == -1) {
                // Brand new group: insert directly into contiguous slot (0 allocations!)
                table[idx].key = counts;
                table[idx].groupIdx = static_cast<int>(res.size());
                res.emplace_back();
            }

            res[table[idx].groupIdx].push_back(std::move(s));
        }
        
        return res;    
    }
};

// optimized sol:

// using CharCounts = array<uint8_t, 26>; 

// struct FastArrayHash {
//     size_t operator()(const CharCounts& arr) const noexcept {
//         const uint64_t* p = reinterpret_cast<const uint64_t*>(arr.data());

//         // Read 24 bytes in three 64-bit chunks, plus the final 2 bytes
//         uint64_t h = p[0] ^ (p[1] * 0x9e3779b97f4a7c15ULL) ^ (p[2] * 0xbf58476d1ce4e5b9ULL);
//         uint16_t tail;
//         std::memcpy(&tail, arr.data() + 24, sizeof(uint16_t));
        
//         h ^= static_cast<uint64_t>(tail) * 0x94d049bb133111ebULL;
//         // Finalizer mix (MurmurHash3 fmix64)
//         h ^= h >> 33;
//         h *= 0xff51afd7ed558ccdULL;
//         h ^= h >> 33;
//         return static_cast<size_t>(h);
//     }
// };

// class Solution {
// public: 
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         // idea: map 26B signatures -> idxs in res vector 
//         // using idx instead of vector avoids nested overheads + moves, i.e. overhead of memory reallocations and dynamic changes then following that into the res, + memory space 
//         unordered_map<CharCounts, int, FastArrayHash> sigToGroupIdx;
//         sigToGroupIdx.reserve(strs.size()); // pre-alloc all buckets
        
//         vector<vector<string>> res; 
//         res.reserve(strs.size()); // pre-alloc resulting vector cap

//         for (string& s: strs) {
//             CharCounts counts {}; // zero-init, already know its 26 by the compiler alias. 
//             for (unsigned char c: s) {
//                 counts[c - 'a']++;
//             }
//             // avoids doublr look-up and inserts if missing, returns iterator if present
//             auto [it, inserted] = sigToGroupIdx.try_emplace(counts, res.size());
//             // i.o. insert at the end if counts isn't in the map, doesn't dynamic because of pre-reserved sigToGroupSize, it = K/V pair and inseted is bool, tru if created, if you do contains you have to hash it again right so use try_emplace for a one-pass, and so try_emplace creates in first path
//             if (inserted) {
//                 res.emplace_back(); // create new group in res if insrted happen in sig 
//             }
            
//             res[it->second].push_back(std::move(s)); 
//             // move stirng from input into final res vector, mainains the k,v index 
//         }
        
//         return res;    
//     }
// };


// Solution 1 

// struct ArrayHash {
//     // optimize hashing -> view 26 bytes -> 3 8 bytes via uint64_t integersand 1 uint16_t integer in ~6 CPU insturctions
//     // map to index instead of vector to avoid storing vector<string> and having oto mmeory allocate size, words placement in res in first path 
//     // if you reserve(size) prevents hashtable from rehashing again 
//     // if you try_emplace() -> hash lookup as oposed to map[key].push_back which has to hash, default construct a vector if missing, and return. a refernce 

//     template<size_t N>
//     size_t operator()(const array<uint8_t, N>& arr) const {
//         size_t hash = 0; 
//         for (int val: arr) {
//             hash ^= std::hash<int>{}(val) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
//         }
//         return hash;
//     }
// };

// // maximize std::move(s)
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> res;

//         unordered_map<array<uint8_t, 26>, vector<string>, ArrayHash> countToWords; 

//         for (const string& str : strs) {
//             array<uint8_t, 26> charCount = {0}; // use uint8_t for the hash to save on bytes 104 bytes -> 26 bytes
//             for (char c: str) {
//                 charCount[c - 'a']++;
//             } 
//             countToWords[charCount].push_back(move(str)); 
//         }

//         for (auto& [count, vec]: countToWords) {
//             res.push_back(move(vec));
//         }

//         return res;
//     }
// };

// sort 

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> map;

//         for (string s: strs) {
//             string key = s;
//             sort(key.begin(), key.end());
//             map[key].push_back(s);
//         }

//         vector<vector<string>> result; 

//         for (auto& pair: map) {
//             result.push_back(std::move(pair.second)); // move instead fo push_back
//         }
//         return result;
//     }
// };
