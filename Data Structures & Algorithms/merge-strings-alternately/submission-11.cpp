using namespace std;


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int m = max(n1, n2);
        
        string result;
        result.reserve(m);
        for (int i = 0; i < m; i++) {
            if (i < n1) {
                result += word1[i];
            }
            if (i < n2) {
                result += word2[i];
            }
        }
        return result;
    }
};