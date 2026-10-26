class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;

        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == val) { continue; }
            
            nums[l] = nums[r]; 
            l++;
        }
        return l; 
    }
};