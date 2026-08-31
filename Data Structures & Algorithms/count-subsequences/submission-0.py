class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        l1, l2 = len(s), len(t)
        def oob(r, c):
            if r < 0 or c < 0 or r >= l1 or c >= l2:
                return True
        # let dp[i] = the number of subsequences that larger_str[:i], smaller_str[:i] have 
        # let dp[i] = dp[i-1] + 
        if not l1 or not l2:
            return 0 

        dp = [[0 for _ in range(l2)] for _ in range(l1)]

        dp[0][0] = 1 if s[0] == t[0] else 0
        for i in range(1, l1):
            if s[i] == t[0]:
                dp[i][0] = dp[i-1][0]

        for j in range(1, l2):
            if s[0] == t[j]:
                dp[0][j] = dp[j-1][0]

        # for row in dp:
        #     print(row)
        # for r in range(1, l1):
        #     for c in range(1, l2):
        #         dp[r][c] = max(dp[r-1][c], dp[r][c-1]) + (1 if s[r] == t[c] else 0)

        for row in dp:
            print(row)
        return dp[-1][-1]