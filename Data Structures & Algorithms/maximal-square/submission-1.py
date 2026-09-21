class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        

        # dp[i][j] = 1 ** 2 (if matrix[i][j] == "1")
        #          + (x - i) ** 2 (if matrix[i:x][j] == "1")
        #          = max area of 1's 


        N, M = len(matrix), len(matrix[0])
        dp = [[0] * M for _ in range(N)]

        for i in range(N):
            dp[i][0] = int(matrix[i][0])
        for j in range(M):
            dp[0][j] = int(matrix[0][j])

        for i in range(1, N):
            for j in range(1, M):
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1] + int(matrix[i][j])

        
        return max(max(row) for row in dp)