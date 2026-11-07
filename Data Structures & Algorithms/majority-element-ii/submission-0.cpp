#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int best1 = 0; 
        int count1 = 0;

        int best2 = 0; 
        int count2 = 0;
        
        for (const int& num : nums ) {
            if (num == best1) {
                count1++;
            } else if (num == best2) {
                count2++;
            } else if (count1 == 0) { 
                best1 = num;
                count1 = 1;
            } else if (count2 == 0) { 
                best2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }



        count1 = count2 = 0;
        for (int num : nums) {
            if (num == best1) count1++;
            else if (num == best2) count2++;
        }

        if (count1 > nums.size() / 3) res.push_back(best1);
        if (count2 > nums.size() / 3) res.push_back(best2);

        return res;
    }
};