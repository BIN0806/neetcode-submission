#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int area = 0; 
        stack<int> st;

        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int bottom = height[st.top()];
                st.pop();

                if (st.empty()) break;

                int left = st.top();
                int width = i - left - 1;
                res += width * (min(height[st.top()], height[i]) - bottom);
            }
            
            st.push(i);
        }
        return res;        
    }
};
