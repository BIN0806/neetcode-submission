#include <iostream>
#include <vector>
// #include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int num: nums) {
            count[num] += 1;
        }

        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first); 
        }

        vector<int> res;
        for (int i = freq.size() - 1; i >= 0; i--) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) break;
            }
        }

        return res;
    }
};
