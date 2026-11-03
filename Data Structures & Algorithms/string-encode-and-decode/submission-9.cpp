#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstring>

using namespace std;
// more optimized:

class Solution {
public:

    string encode(vector<string>& strs) {
        const uint32_t count = static_cast<uint32_t>(strs.size());

// caclculate size to do 1 single heap allocations of strings, instead of += repeats
        size_t total_bytes = sizeof(uint32_t); 
        for (const string&s : strs) {
            total_bytes += s.size() + sizeof(uint32_t);
        }

        string res(total_bytes, '\0'); // uninit resize in 23, standard resice 
        char* __restrict out = res.data(); 

        memcpy(out, &count, sizeof(uint32_t));
        out += sizeof(uint32_t);

        // appends in-place (avoids '+' temporary string allocations!)
        for (const string& s: strs) {
            const uint32_t len = static_cast<uint32_t>(s.size());
            memcpy(out, &len, sizeof(uint32_t));
            out += sizeof(uint32_t);

            if (len > 0) {
                memcpy(out, s.data(), len);
                out += len;
            }
        }

        return res;
    }

    vector<string> decode(string s) {
        const char* __restrict in = s.data();

        uint32_t count = 0;
        memcpy(&count, in, sizeof(uint32_t));
        in += sizeof(uint32_t);

        vector<string> res; 
        res.reserve(count);

        for (uint32_t i = 0; i < count; i++){
            size_t len = 0;
            memcpy(&len, in, sizeof(uint32_t)); // cool string number trick
            in += sizeof(uint32_t);
        
            res.emplace_back(in, len);
            in += len;
        }

        return res;
    }
};




// optimized:
// class Solution {
// public:

//     string encode(vector<string>& strs) {
//         // caclculate size to do 1 single heap allocations of strings, instead of += repeats
//         size_t total_bytes = 0; 
//         for (const string&s : strs) {
//             total_bytes += s.size() + 5;
//         }

//         string res;
//         res.reserve(total_bytes);

//         // appends in-place (avoids '+' temporary string allocations!)
//         for (const string& s: strs) {
//             res.append(to_string(s.size()));
//             res.push_back('#');
//             res.append(s);
//         }

//         return res;
//     }

//     vector<string> decode(string s) {
//         vector<string> res; 
//         const size_t n = s.size();
//         const char* __restrict data = s.data();
//         size_t i = 0;

//         while (i < n) {
//             size_t len = 0;
//             while (data[i] != '#') {
//                 len = len * 10 + (data[i] - '0'); // cool string number trick
//                 ++i;
//             }
//             ++i; // '#' delim

//             res.emplace_back(data + i ,len);
//             i += len;
//         }

//         return res;
//     }
// };



// class Solution {
// public:

//     string encode(vector<string>& strs) {
//         string res;
//         for (const string& s: strs) {
//             res += to_string(s.length()) + "#" + s;
//         }
//         return res;
//     }

//     vector<string> decode(string s) {
//         vector<string> res; 
//         int i = 0;

//         while (i < s.length()) {
//             size_t pos = s.find('#', i); // at index i find the index of '#', use single
//             int length = stoi(s.substr(i, pos - i)); // get the number from i to pos - i
//             res.push_back(s.substr(pos + 1, length));
//             i = pos + 1 + length;
//         }

//         return res;
//     }
// };
