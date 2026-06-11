class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        complete_total = sum([i for i in range(0, n+1)])
        print(complete_total)
        for num in nums:
            complete_total -= num
        return complete_total