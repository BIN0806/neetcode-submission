#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <algorithm> 

using namespace std; 


// Solution 1 

struct ArrayHash {
    // optimize hashing -> view 26 bytes -> 3 8 bytes via uint64_t integersand 1 uint16_t integer in ~6 CPU insturctions
    // map to index instead of vector to avoid storing vector<string> and having oto mmeory allocate size, words placement in res in first path 
    // if you reserve(size) prevents hashtable from rehashing again 
    // if you try_emplace() -> hash lookup as oposed to map[key].push_back which has to hash, default construct a vector if missing, and return. a refernce 

    template<size_t N>
    size_t operator()(const array<uint8_t, N>& arr) const {
        size_t hash = 0; 
        for (int val: arr) {
            hash ^= std::hash<int>{}(val) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

// maximize std::move(s)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<array<uint8_t, 26>, vector<string>, ArrayHash> countToWords; 

        for (const string& str : strs) {
            array<uint8_t, 26> charCount = {0}; // use uint8_t for the hash to save on bytes 104 bytes -> 26 bytes
            for (char c: str) {
                charCount[c - 'a']++;
            } 
            countToWords[charCount].push_back(move(str)); 
        }

        for (auto& [count, vec]: countToWords) {
            res.push_back(move(vec));
        }

        return res;
    }
};

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
