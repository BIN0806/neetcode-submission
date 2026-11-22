#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        int n = nums.size();
        int l = 0;

        for (int r = 0; r < min(k, n); ++r) {
            if (seen.contains(nums[r])) { return true;}
            seen.insert(nums[r]);
        }

        for (int r = k; r < n; ++r) {
            if (seen.contains(nums[r])) { return true;}
            seen.insert(nums[r]);
            seen.erase(nums[l++]);
        }

        return false;
    }
};