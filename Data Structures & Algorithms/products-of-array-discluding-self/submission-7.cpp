#include <vector>
#include <iostream>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; ++i) {
            prefix[i] = nums[i] * prefix[i - 1];
            suffix[n-1-i] = nums[n-1-i] * suffix[n-i];
        }

        // for (int i = 0; i < n; i++) {
        //     cout << prefix[i] << " ";
        // }
        // cout << '\n';


        // for (int i = 0; i < n; i++) {
        //     cout << suffix[i] << " ";
        // }
        // cout << '\n';

        vector<int> result(n, 0); 
        result[0] = suffix[1];
        result[n-1] = prefix[n-2];

        for (int i = 1; i < n - 1; ++i) {
            result[i] = prefix[i-1] * suffix[i+1];
        }

        return result;
    }
};
