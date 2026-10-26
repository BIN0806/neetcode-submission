#include <iostream>
#include <cmath> 
#include <unordered_map>

using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;

        for (int num : nums) {
            counter[num] += 1;
        }

        auto it = std::max_element(
            counter.begin(), 
            counter.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            }
        );
        
        return it->first;
    }
};