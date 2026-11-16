#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); 
        int cur_sum;
        int l, r;
        for (int i = 0; i < nums.size(); ++i) {
            l = i + 1, r = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) { continue; }
            while (l < r) {
                cur_sum = nums[i] + nums[l] + nums[r]; 
                if (cur_sum == 0) {
                    res.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    r--;
                    
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;    
                    }
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;    
                    }
                    
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
