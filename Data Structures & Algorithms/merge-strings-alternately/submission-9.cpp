using namespace std;


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        string result;

        for (int i = 0; i < n1 || i < n2; i++) {
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