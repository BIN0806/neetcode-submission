class Solution {
public:
    bool isPalindrome(string s, int l, int r, int k) {
        while (l < r) {
            while (l < r && !isalnum(s[l])) {l++;}
            while (r > l && !isalnum(s[r])) {r--;}

            if (tolower(s[l]) != tolower(s[r]) || k > 0) { 
                return isPalindrome(s, l++, r , k - 1) || isPalindrome(s, l, r-- , k - 1); 
            }
            
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        return isPalindrome(s, 0, s.size() - 1, 1);
    }
};