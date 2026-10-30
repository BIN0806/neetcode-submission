#include <vector> 
#include <array> 

#include <utility> // for swap (move semantics instead of copy)

using namespace std; 

class Solution {
private: 
    void quickSort3Way(vector<int>& nums, int low, int high) noexcept {
        if (low >= high) return; 

        // pick middle element as pivot to avoid worst case on already sorted inputs
        int pivot = nums[low + ((high - low) >> 1)];

        int lt = low, i = low, gt = high;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[lt++], nums[i++]);
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[gt--]);
            } else {
                ++i;
            }
        }

        quickSort3Way(nums, low, lt - 1);
        quickSort3Way(nums, gt + 1, high);
    }

public: 
    vector<int> sortArray(vector<int>& nums) {
        quickSort3Way(nums, 0, static_cast<int>(nums.size()) -1);
        return nums;
    }
};

// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         // 1000000 => 400KB = K
//         // TIME: O(n+K) ; SPACE: O(K)
//         static constexpr int RANGE = 100001;
//         static constexpr int OFFSET = 50000;
//         array<int, RANGE> count{0}; // 0 init array 

//         for (const int& num: nums) { // reference a const, but ints are faster generally. to coopy, 4B only!, compilers optimize this too lol
//             ++count[(num*) + OFFSET]; // simple increment
//         }

//         int idx = 0;
//         for (int i = 0; i < RANGE; i++) {
//             // move it out the while loop to avoid CPU 
//             const int val = i - OFFSET;
//             int freq = count[i];
//             while (freq > 0) {
//                 nums[idx++] = val;
//                 --freq;
//             }

//         }

//         return nums;
//     }
// };