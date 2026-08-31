class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n1, n2 = len(s),len(p)
        dp = [[False] * (n2 + 1) for _ in range(n1 +1)]
        dp[n1][n2] = True 
        # dp[(i, j)] = if s[i:] == p[j:] and at the end it's true 
        # in english the state represent's whether any after indexes (i, j) are equal in Regex

        for j in range(n2-2,-1,-1):
            if p[j + 1] == "*":
                dp[n1][j] = dp[n1][j+2] # To include or not include the case where .* exists, for all pairs

        for i in range(n1-1, -1, -1):
            for j in range(n2-1, -1, -1):
                match = (s[i] == p[j] or p[j] == ".")

                if j + 1 < n2 and p[j+1] == "*":
                    dp[i][j] = dp[i][j+2] or (match and dp[i+1][j])
                elif match:
                    dp[i][j] = dp[i+1][j+1]
    
        return dp[0][0] 

        # Top-Down 
        # dp = {} # dp[(i, j)] = if s[i:] == p[j:]

        # def dfs(i, j):
        #     if (i, j) in dp:
        #         return dp[(i, j)]
        #     if i >= n1 and j >= n2: 
        #         return True 
        #     if j >= n2:
        #         return False

        #     match = i < n1 and (s[i] == p[j] or p[j] == ".")
        #     # Handles star case
        #     if (j + 1) < n2 and p[j+1] == "*":
        #         dp[(i, j)] = ((dfs(i, j + 2)) or  # don't use, it (hence the non-inc i)
        #                     (match and dfs(i+1, j)))         # use it and we don't increment it because of future use of *
        #         return dp[(i, j)]

        #     if match:
        #         dp[(i, j)] = dfs(i + 1, j + 1)
        #         return dp[(i, j)]
        #     # No match
        #     dp[(i, j)] = False
        #     return False
        # return dfs(0, 0)