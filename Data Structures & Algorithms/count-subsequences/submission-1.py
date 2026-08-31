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
            dp[i][0] = dp[i-1][0] + (1 if s[i] == t[0] else 0)

        print("pre")
        for row in dp:
            print(row)

        for r in range(1, l1):
            for c in range(1, l2):
                dp[r][c] = dp[r-1][c] + (dp[r-1][c-1] if s[r] == t[c] else 0)
        
        print("pos")
        for row in dp:
            print(row)

        return dp[-1][-1]