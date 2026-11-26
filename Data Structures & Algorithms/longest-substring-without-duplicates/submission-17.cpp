#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int n = s.size();
        int l = 0;
        unordered_set<char> seen;

        for (int r = 0; r < n; ++r) {
            while (l < r && seen.contains(s[r])) {
                seen.erase(s[l++]);
            } 
            seen.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
