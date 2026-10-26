#include <iostream>
#include <cmath> 
#include <unordered_map>

using namespace std;

class Solution {
public: 
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (const int& num: nums) {
            // cerr << "num: " << num
            //     << " candidate: " << candidate
            //     << " count: " << count << '\n';            
            if (count == 0) { 
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
            // if (num == candidate) {
            //     count += 1;
            // } else {
            //     count -= 1;
            // }
        }
        return candidate;
    }
};

// Native O(N) space, time
// Optimzed to 1 PASS
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int half = nums.size() / 2;
//         unordered_map<int, int> counter;

//         for (int num : nums) {
//             if (++counter[num] > half) {
//                 return num;
//             }
//         }

//         // auto it = std::max_element(
//         //     counter.begin(), 
//         //     counter.end(),
//         //     [](const auto& a, const auto& b) {
//         //         return a.second < b.second;
//         //     }
//         // );
        
//         // return it->first;
//     }
// };

