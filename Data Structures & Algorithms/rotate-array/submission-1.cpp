#include <vector> 

using namespace std; 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        int l = 0, r = n - k;
        while (r < n)
            swap(nums[l++], nums[r++]);

    }
};