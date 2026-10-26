#include <iostream>
#include <cmath> 
#include <unordered_map>

using namespace std;

// Native O(N) space, time
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int half = nums.size() / 2;
        unordered_map<int, int> counter;

        for (int num : nums) {
            if (++counter[num] > half) {
                return num;
            }
        }

        // auto it = std::max_element(
        //     counter.begin(), 
        //     counter.end(),
        //     [](const auto& a, const auto& b) {
        //         return a.second < b.second;
        //     }
        // );
        
        // return it->first;
    }
};