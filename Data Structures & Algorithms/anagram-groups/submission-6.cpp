#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>


using namespace std; 

struct ArrayHash {
    template<size_t N>
    size_t operator()(const array<int, N>& arr) const {
        size_t hash = 0; 
        for (int val: arr) {
            hash ^= std::hash<int>{}(val) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<array<int, 26>, vector<string>, ArrayHash> countToWords; 

        for (const string& str : strs) {
            array<int, 26> charCount = {0};
            for (char c: str) {
                charCount[c - 'a']++;
            } 
            countToWords[charCount].push_back(str);
        }

        for (auto& [count, vec]: countToWords) {
            res.push_back(std::move(vec));
        }

        return res;
    }
};
