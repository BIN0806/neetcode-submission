class Solution {
public:
    bool isPalindrome(string s, int k) {
        int l = 0, r = s.size() - 1; 
        while (l < r) {
            while (l < r && !isalnum(s[l])) {l++;}
            while (r > l && !isalnum(s[r])) {r--;}

            while (tolower(s[l++]) != tolower(s[r--]) || --k < 0) { return false; }        
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        return isPalindrome(s, 1);
    }
};