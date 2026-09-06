class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = set(nums) # num -> cur_size of previous values 
        longest = 0

        for num in nums:
            # print(f"BEFORE {seen} @ {num}")
            if num-1 not in seen: # Optimization, only updates edges
                cur = 1
                while num+cur in seen:
                    cur += 1
                longest = max(longest, cur)

            # print(f"AFTER {seen} @ {num}, Longest: {longest}")

        return longest