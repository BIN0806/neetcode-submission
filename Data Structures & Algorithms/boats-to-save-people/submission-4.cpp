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
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                l++;
                r--;
            } else {
                r--;
            }

            res++;
        }

        return res;        
    }
};