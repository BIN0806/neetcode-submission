// #include <vector>
// #include <stack>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0;
//         stack<int> st;

//         // [0, 2, 0, 3, 1, 0, 1, 3]
//         // []
//         // bottom = 0
//         // width = 1 

//         for (int i = 0; i < height.size(); ++i) {
//             while (!st.empty() && height[i] > height[st.top()]) {
//                 int bottom = height[st.top()];
//                 st.pop();

//                 if (st.empty()) break;

//                 int left = st.top();
//                 int width = i - left - 1;
//                 res += width * (min(height[st.top()], height[i]) - bottom);
//             }
            
//             st.push(i);
//         }
//         return res;        
//     }
// };


#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        int res = 0;
        int l = 0, r = height.size() - 1;
        int maxL = height[l], maxR = height[r];
        
        while (l < r) {
            if (maxL < maxR) {
                l++;
                maxL = max(maxL, height[l]);
                res +=  maxL - height[l];
            } else {
                r--;
                maxR = max(maxR, height[r]);
                res +=  maxR - height[r];
            }
        }
        return res;        
    }
};

