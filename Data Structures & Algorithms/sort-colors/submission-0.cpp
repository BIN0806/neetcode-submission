#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    // void sortColors(vector<int>& nums) noexcept {
    //     const size_t n = nums.size();
    //     int* __restrict data = nums.data();
        
    //     // Keep counters in CPU registers
    //     size_t c0 = 0;
    //     size_t c1 = 0; 


    //     for (size_t i = 0; i < n; i++) {
    //         int val = data[i];
    //         c0 += (val == 0); // compiles to SETE/ADD insc
    //         c1 += (val == 1);
    //     }

    // std::fill_n(data, c0, 0);
    // std::fill_n(data + c0, c1, 1);
    // std::fill_n(data + c0 + c1, n - c0 - c1, 2);
    // }
    void sortColors(vector<int>& nums) noexcept {
        int* __restrict data = nums.data();
        int low = 0;
        int mid = 0;
        int high = static_cast<int>(nums.size()-1);

        while (mid <= high) {
            int val = data[mid];
            if (val == 0) {
                swap(data[low++], data[mid++]);
            } else if (val == 2) {
                swap(data[mid], data[high--]);
            } else{ 
                ++mid;
            }
        }
    }
};