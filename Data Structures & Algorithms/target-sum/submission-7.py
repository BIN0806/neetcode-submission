class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = {}
        # dp[i] = # of ways to sum to target from i {i being an }
        def dfs(i, total):
            if i == len(nums):
                if total == target:
                    return 1
                return 0 
            if (i, total) in dp:
                return dp[(i, total)] 
            
            dp[(i, total)] = dfs(i + 1, total + nums[i]) + dfs(i + 1, total - nums[i])

            return dp[(i, total)]

        return dfs(0, 0)