#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
                
        int n = nums.size();
        int l, r;
        long long sum;

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {continue;}
            for (int j = i + 1 ; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {continue;}
                l = j + 1, r = n - 1;
                while (l < r) {
                    sum =  1LL * nums[l] + nums[r] + nums[i] + nums[j];
                    if (sum == target) {
                        res.push_back({nums[r], nums[l], nums[i], nums[j]});
                        l++; 
                        r--;
                        
                        while (l < r && nums[l] == nums[l - 1]) {l++;}
                        while (l < r && nums[r] == nums[r + 1]) {r--;};
                    }
                    else if (sum > target) {
                        r--;
                    }
                    else if (sum < target) {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};