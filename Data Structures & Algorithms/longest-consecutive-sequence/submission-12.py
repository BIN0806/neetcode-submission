class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = set() # num -> cur_size of previous values 
        longest = 0

        for num in nums:
            cur = 1
            seen.add(num)
            while num-cur in seen:
                cur += 1
                seen.add(num-cur)
            longest = max(longest, cur)


        return longest