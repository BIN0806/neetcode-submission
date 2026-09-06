class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = set(nums) # num -> cur_size of previous values 
        longest = 0

        for num in nums:
            # print(f"BEFORE {seen} @ {num}")

            cur = 1
            while num+cur in seen:
                cur += 1
            longest = max(longest, cur)

            # print(f"AFTER {seen} @ {num}, Longest: {longest}")

        return longest