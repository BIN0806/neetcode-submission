#include <iostream>
#include <string>
#include <format>
using std::cout;
using std::endl;



class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }
        int count[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            // cout << "Count of " << static_cast<char>('a' + i) << " is " << count[i];
            if (count[i] != 0) {return false;}
        }
        return true;
    }
};