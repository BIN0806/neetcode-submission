#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int res = 0;

        sort(people.begin(), people.end());

        int l = 0, r = n - 1;
        while (l < r) {
            if (people[r] == limit) {
                res++;
                r--;
                continue;
            }

            if (people[l] + people[r] <= limit) {
                res++;
                l++;
                r--;
            } else {
                res++;
                res++;
                l++;
                r--;
            }
        }
        if (l == r) res++;

        return res;        
    }
};