#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (string s: strs) {
            res += to_string(s.length()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res; 
        int i = 0;

        while (i < s.length()) {
            size_t pos = s.find("#", i); // at index i find the index of '#'
            int length = stoi(s.substr(i, pos - i)); // get the number from i to pos - i
            res.push_back(s.substr(pos + 1, length));
            i = pos + 1 + length;
        }

        return res;
    }
};
