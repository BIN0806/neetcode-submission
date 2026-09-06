class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        map = {} # num -> cur_size of previous values 

        for num in nums:
            if num-1 in map: 
                map[num] = 1 + map[num-1]
            else:
                map[num] = 1
        

        return max(map.values())