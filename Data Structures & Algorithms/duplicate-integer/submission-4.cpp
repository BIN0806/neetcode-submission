#include <iostream>
#include <set>


class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        // std::set<int> mySet; 
        // for (int num : nums) {
        //     if (mySet.contains(num)) {
        //         return true;
        //     }     
        //     mySet.insert(num);
        // }
        // return false;
        std:unordered_set<int> seen(nums.begin(), nums.end());
        return seen.size() < nums.size();
    }
};