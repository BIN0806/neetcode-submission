#include <vector> 
#include <ranges> 

using namespace std; 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n

        int temp;
        for (const auto& [index, num] : view::enumerate(nums)) {
            temp = nums[(index + k) % n];
            nums[(index + k) % n] = num;

        }

    }
};