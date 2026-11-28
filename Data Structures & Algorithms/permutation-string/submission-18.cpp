#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(); 
        if (n1 > n2) { return false; }
        
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        for (int i = 0; i < n1; ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            if (s1Count[i] == s2Count[i]) {matches++;}
        }

        // s2 represents our sliding window
        
        int l = 0;  
        int index;
        for (int r = n1; r < n2; ++r) {
            if (matches == 26) {
                return true;
            }
            
            index = s2[r] - 'a';
            s2Count[index]++;
            if (s1Count[index] == s2Count[index]) { matches++; }
            else if (s1Count[index] + 1 == s2Count[index]) { matches--; }
            
            index = s2[l] - 'a';
            s2Count[index]--;
            if (s1Count[index] == s2Count[index]) { matches++; }
            else if (s1Count[index] + 1 == s2Count[index]) { matches--; }

            l++;
        }   

        return matches == 26;       
    }
};
