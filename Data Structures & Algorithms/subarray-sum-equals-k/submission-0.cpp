#include <vector> 
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;

        unordered_map<int, int> cnt; 
        cnt[0] = 1;

        int running_sum = 0;
        for (int i = 0; i < n; i++) {
            running_sum += nums[i];

            res += cnt[running_sum - k]; 
            cnt[running_sum]++;
        }

        return res;
    }
};