class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        dp = {} # -> Subproblem: The interval maps to best value
        # dp[(l, r)] = the max value on interval nums[l:r]
        def dfs(l, r):  
            # Terminate once not-valid interval 
            if l > r:
                return 0 

            if (l, r) in dp:
                return dp[(l, r)]

            dp[(l, r)] = 0 # Base case for all ranges
            for i in range(l, r +1):
                coins = nums[l - 1] * nums[i] * nums[r + 1] # ROOT
                coins += dfs(l, i - 1) + dfs(i + 1, r)      # Subchildren Problem's
                dp[(l, r)] = max(dp[(l, r)], coins)         # Best on the interval is the Max of O(N) ROOTs
            return dp[(l, r)]

        return dfs(1, len(nums) - 2)