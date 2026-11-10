class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;

        while (l < r) {
            while (s[l] == ' ' || !isalnum(s[l])) {l++;}
            while (s[r] == ' ' || !isalnum(s[r])) {r--;}
            
            if (l >= r) { break; }

            if (tolower(s[l++]) != tolower(s[r--])) { return false; }        
        }

        return true;
    }
};
