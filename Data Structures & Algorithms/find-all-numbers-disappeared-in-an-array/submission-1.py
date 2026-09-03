class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # n = len(nums)
        # res = set(range(1, n+1))

        # for num in nums:
        #     if num in res:
        #         res.remove(num)
                
        # return list(res)


        n = len(nums)

        # map numbers in nums to bools in the nums array by using the sign operator
        for num in nums:
            idx = abs(num) - 1
            nums[idx] = -abs(nums[idx]) # negative means taken, so make it negative if > 1 time

        res = []
        for i in range(n):
            num = nums[i]
            if num > 0:
                res.append(i + 1)
                
        return res