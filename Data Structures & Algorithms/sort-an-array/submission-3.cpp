#include <vector> 
#include <array> 

using namespace std; 

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 1000000 => 400KB = K
        // TIME: O(n+K) ; SPACE: O(K)
        static constexpr int OFFSET = 50000;
        array<int, 100001> count{0}; // 0 init array 

        for (int num: nums) {
            ++count[num + OFFSET]; // simple increment
        }

        int idx = 0;
        for (int i = 0; i <= 100000; i++) {
            // move it out the while loop to avoid CPU 
            const int val = i - OFFSET;
            int freq = count[i];
            while (freq > 0) {
                nums[idx++] = val;
                --freq;
            }

        }

        return nums;
    }
};