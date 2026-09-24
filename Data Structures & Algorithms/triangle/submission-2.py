class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # ROWS = len(triangle)
        # dp = [float('inf')] * ROWS

        # # [[2],
        # # [-3,4],
        # # [100,99,7],
        # # [4,1,-8,3]]

        # # [ 2
        # #   -1
        # # 
        # #     ]
        # dp[0] = triangle[0][0]
        # for i in range(1, ROWS):
        #     for j in range(len(triangle[i]) - 1):
        #         dp[i] = min(dp[i], dp[i-1] + triangle[i][j], dp[i-1] + triangle[i][j+1]) 
                
        # return dp[-1]

        for row in range(len(triangle) - 2, -1, -1):
            for col in range(len(triangle[row])):
                triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1])
        return triangle[0][0]