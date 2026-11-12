using namespace std;


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if (word1.size() > word2.size()) {
            swap(word1, word2);
        }

        int n1 = word1.size();
        int n2 = word2.size();
        string result;

        for (int i = 0; i < n1; i++) {
            result += word1[i];
            result += word2[i];
        }

        while (n1 < n2) {
            result += word2[n1];
            n1++;
        }

        return result;
    }
};