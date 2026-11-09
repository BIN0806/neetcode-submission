#include <vector>
#include <unordered_set> 
#include <iostream>
#include <cmath>

using namespace std; 

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // UF them 
        // go through key in sorted order (nlogn); not sufficient 


        // obseravtion output range: (1, len(nums) + 1)
        // the length is 10**6 
        // but b-search solution, needs sorted which is nlogn, bc arr isn't sorted 
        
        // for i in range(1, len + 2): 
        // on the set(nums) => O(N)

        // idea: use extra memory to O(1) using input as extra memoery 
        // how to use an arr as an hashset? 
        // arr[indx] -> to values 
        // each of values has an index to input arr 
        
        // value - 1 = idx of location
        // at this negatives indicate true 
        // but negative numbers in the arr! 
            // => it doesn't matter, get rid of it! (i.e. change it to 0, so it doesnt' affect postivie and negative to indicate)


        // 1st iteration
            // mark negatives as 0 

        // 2nd iteration
            // mark number in the mapped arr, only if in-bounds and if not negative already 
                // make numbers negative at arr[abs(val) - 1] = -1 * arr[abs(val) - 1]
                // issue what if arr[abs(val) - 1] is 0 ? how to negatively indicate that? // use inf?; 
                // just use -(len(A) + 1), since thats the outbound
            
        // 3rd iteration
            // go through outspace space; and verify if its in by checking indicators
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) { nums[i] = 0; }
        }

        int idx; 
        for (int i = 0; i < n; i++) {
            idx = abs(nums[i]) - 1;
            if (idx < 0 or idx >= n) {
                continue;
            } 
            
            if (nums[idx] == 0) { 
                nums[idx] = n + 1; 
            }

            nums[idx] *= -1;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i;
            }
        }

        return n + 1;
    }
};