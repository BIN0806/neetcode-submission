#include <iostream>
#include <vector>
#include <string>

using namespace std;
// optimized:
class Solution {
public:

    string encode(vector<string>& strs) {
        // caclculate size to do 1 single heap allocations of strings, instead of += repeats
        size_t total_bytes = 0; 
        for (const string&s : strs) {
            total_bytes += s.size() + 5;
        }

        string res;
        res.reserve(total_bytes);

        // appends in-place (avoids '+' temporary string allocations!)
        for (const string& s: strs) {
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res; 
        const size_t n = s.size();
        const char* __restrict data = s.data();
        size_t i = 0;

        while (i < n) {
            size_t len = 0;
            while (data[i] != '#') {
                len = len * 10 + (data[i] - '0'); // cool string number trick
                ++i;
            }
            ++i; // '#' delim

            res.emplace_back(data + i ,len);
            i += len;
        }

        return res;
    }
};



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
