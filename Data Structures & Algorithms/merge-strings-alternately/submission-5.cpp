using namespace std;


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        int minLen = min(n1, n2);
        int maxLen = max(n1, n2);

        const char* ptr;

        if (n1 <= n2) {
            ptr = &word2[n1];
        } else {
            ptr = &word1[n2];
        }

        string result;

        for (int i = 0; i < minLen; i++) {
            result += word1[i];
            result += word2[i];
        }

        for (;minLen < maxLen; minLen++) {
            result += *ptr[minLen];
        }

        return result;
    }
};