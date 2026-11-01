#include <iostream>
#include <vector>
// #include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count.reserve(nums.size());

        for (int num: nums) {
            ++count[num];
        }
        // continous arr of freq, val pairs
        vector<pair<int, int>> flat;
        flat.reserve(count.size());
        for (const auto& [val, freq] : count) {
            flat.emplace_back(freq, val); // in-place no temporary copy
        }
        // in-place quick select, to patition 
        // the top k largest frequencies to the front

        nth_element(
            flat.begin(),
            flat.begin() + k, 
            flat.end(),
            greater<pair<int,int>>()
        );

        vector<int> res;
        res.reserve(k); 
        for (int i = 0; i < k; i++) {
            res.push_back(flat[i].second);
        }
        return res;
    }
};
