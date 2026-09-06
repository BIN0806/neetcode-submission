class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seen = set() # num -> cur_size of previous values 
        longest = 0

        for num in nums:
            if num-1 in seen: 
                longest += 1


        return longest