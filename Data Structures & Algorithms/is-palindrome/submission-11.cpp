class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            
            while (s[l++] == ' ') {}
            while (s[r--] == ' ') {}
        }

        return true;
    }
};
