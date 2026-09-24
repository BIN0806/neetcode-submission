class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        ROWS = len(triangle)
        dp = [float('inf')] * ROWS

        dp[0] = triangle[0][0]
        for i in range(1, ROWS):
            for j in range(len(triangle[i])-1):
                dp[i] = min(dp[i], dp[i-1] + triangle[i][j], dp[i-1] + triangle[i][j+1]) 
                
        return dp[-1]