#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0;
        int l = 0, maxf = 0;
        for (int r = 0; r < s.size(); ++r) {
            maxf = max(maxf, ++count[s[r]]);
            while ((r - l + 1) - maxf > k) {
                count[s[l++]]--;
            }

            res = max(res, r - l + 1);
        }


        return res;
    }
};
