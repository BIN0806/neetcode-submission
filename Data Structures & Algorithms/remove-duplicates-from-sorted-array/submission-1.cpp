#include <climits>
using namespace std;

// [2,10,10,30,30,30]
//  
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), l = 1;

        for (int r = 1; r < n; r++) {
            if (nums[r] != nums[r - 1]) {
                nums[l++] = nums[r];
            }
        }        

        return l;
    }
};