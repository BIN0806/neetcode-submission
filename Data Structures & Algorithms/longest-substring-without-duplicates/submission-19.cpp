#include <unordered_set>
#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int n = s.size();
        int l = 0;
        unordered_map<char, int> mp;

        for (int r = 0; r < n; ++r) {
            if (l < r && mp.contains(s[r])) {
                l = max(mp[s[r]] + 1, l);
            } 
            mp[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
