class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> sum_to_idx = {};

        int num;
        int complement;
        for (int i = 0; i < nums.size(); i++) {
            num = nums[i];
            complement = target - num;
            if (sum_to_idx.contains(num)) {
                return {sum_to_idx[num], i};
            } 
            sum_to_idx[complement] = i;
        }
    }
};
