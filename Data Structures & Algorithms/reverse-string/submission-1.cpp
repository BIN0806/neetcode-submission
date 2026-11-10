using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
       int l = 0;   
       int n = s.size();
       char c;
       for (int r = n - 1; r >= 0; --r) {
            if (l > r) { break; }

            c = s[l];
            s[l] = s[r];
            s[r] = c;
            l++;
       } 
    }
};