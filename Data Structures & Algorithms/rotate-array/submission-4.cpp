#include <vector> 
#include <algorithm>
using namespace std; 

// [1, 2, 3, 4, 5]
// [5, 4, 3, 2, 1]
// [4, 5, 1, 2, 3]

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

private:
    void reverse(vector<int>::iterator start, vector<int>::iterator end) {
        end--;
        while (start < end) {swap(*start, *end); end--; start++;}
    }

};