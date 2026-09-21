class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        

        # dp[i][j] = 1 ** 2 (if matrix[i][j] == "1")
        #          + (x - i) ** 2 (if matrix[i:x][j] == "1")
        #          = max area of 1's 


        N, M = len(matrix), len(matrix[0])
        dp = [[0] * (M+1) for _ in range(N+1)]


        for i in range(N-1,-1,-1):
            for j in range(M-1,-1,-1):
                if int(matrix[i][j]):
                    dp[i][j] = min(dp[i+1][j+1], dp[i+1][j], dp[i][j+1]) + int(matrix[i][j])

        
        return max(max(row) for row in dp) ** 2