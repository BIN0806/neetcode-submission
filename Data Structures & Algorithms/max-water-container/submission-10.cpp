#include <vector> 

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;

        int best = 0;
        while (l < r) {
            best = max( (r - l) * min(heights[l], heights[r]), best);
            cout << best << endl;
            if (heights[r] < heights[l]) {r--;}
            else {l++;}
        }
        return best;
    }
};
