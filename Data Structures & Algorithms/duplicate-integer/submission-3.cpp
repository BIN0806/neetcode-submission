#include <iostream>
#include <set>


class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        std::set<int> mySet; 
        for (int num : nums) {
            if (mySet.contains(num)) {
                return true;
            }     
            mySet.insert(num);
        }
        return false;
    }
};