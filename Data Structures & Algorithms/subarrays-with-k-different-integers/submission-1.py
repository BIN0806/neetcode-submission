from collections import defaultdict

class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        # def atMost(k: int):
        #     count = 0
        #     n = len(nums)
        #     counter = defaultdict(int)
        #     l = 0
        #     for r in range(n):
        #         counter[nums[r]] += 1

        #         while len(counter) > k:
        #             counter[nums[l]] -= 1
        #             if counter[nums[l]] == 0:
        #                 del counter[nums[l]]
        #             l += 1

        #         count += r - l + 1
        #     return count 
        # if k == 0: 
        #     return 0
        # return atMost(k) - atMost(k-1)

        n = len(nums)
        counter = defaultdict(int)
        l = res = count = 0

        for r in range(n):
            counter[nums[r]] += 1
            if counter[nums[r]] == 1:
                k -= 1

            if k < 0:
                counter[nums[l]] -= 1
                l += 1
                k += 1
                count = 0
            
            if k == 0:
                while counter[nums[l]] > 1:
                    counter[nums[l]] -= 1
                    l += 1
                    count += 1

                res += r - l + 1
        return res 
       
