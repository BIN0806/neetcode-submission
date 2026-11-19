class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= n - 1; // hamming weight the idea is to remove one "1" at a time from left to right
            res++;
        }
        return res;
    }
};
