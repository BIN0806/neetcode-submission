class Solution {
public:
    bool isPalindrome(string s, int k) {
        int l = 0, r = s.size() - 1; 
        while (l < r) {
            while (l < r && !isalnum(s[l])) {l++;}
            while (r > l && !isalnum(s[r])) {r--;}

            if (tolower(s[l]) != tolower(s[r])) { return false; }        
            else if (k > 0) {
                if (l < r && tolower(s[l + 1])) { l++;}
                else if (r > l && tolower(s[r - 1])) { r--;}
                k--;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        return isPalindrome(s, 1);
    }
};