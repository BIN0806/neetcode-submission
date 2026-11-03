#include <vector>
#include <iostream>


using namespace std; 

class Solution {
public:
    // optimized: 
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);  
        // actually don't need to 0 init all, just idx 0

        const int* __restrict in = nums.data();
        int* __restrict out = result.data();

        int prefix = 1; // keep in registers (write-only on out, not store to load stall)
        for (int i = 1; i < n; ++i) {
            out[i] = prefix;
            prefix *= in[i];
        }

        int posfix = 1;
        for (int i = n - 1; i >= 0; --i) {
            out[i] *= posfix;
            posfix *= in[i];
        }

        return result;
    }

    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> result(n, 1); 
 
    //     for (int i = 1; i < n; ++i) {
    //         result[i] = result[i - 1] * nums[i - 1];
    //     }

    //     int posfix = 1;
    //     for (int i = n - 1; i >= 0; --i) {
    //         result[i] *= posfix;
    //         posfix *= nums[i];
    //     }

    //     return result;
    // }
};
