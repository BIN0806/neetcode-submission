    
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0; 
        int cur = 0;
        for (int r = 0; r < prices.size(); r ++) {
            if (prices[r] > prices[l]) {
                cur += prices[r] - prices[l];
            }                
            l = r;
        }
        return cur;
    }
};