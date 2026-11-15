#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1; 
        int cur_sum;
        
        for (int i = 0; i < nums.size(); ++i) {
            while (l < r) {
                cur_sum = nums[i] + nums[l] + nums[r]; 
                if (cur_sum == 0) {
                    res.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    r--;
                }
                else if (cur_sum > 0) {
                    r--;
                }
                else if (cur_sum < 0) {
                    l++;
                }
            }
        }
        return res;
    }
};
