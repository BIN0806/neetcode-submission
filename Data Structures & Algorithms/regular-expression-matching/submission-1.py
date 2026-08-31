class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n1, n2 = len(s),len(p)

        # for j in range(n2):
        #     for i in range(n1):
        #         if s[i] == p[j] or p[j] == ".":
        #             continue 

        #         if p[j] == "*": # based on assumption we know its i >= 1
        #             while n2 > j >= 1 and p[j-1] == s[i] or p[j-1] == ".":  
        #                 continue

        #         return False 
    
        # return True 


        dp = {} # dp[(i, j)] = if s[i:] == p[j:]

        def dfs(i, j):
            if (i, j) in dp:
                return dp[(i, j)]
            if i >= n1 and j >= n2: 
                return True 
            if j >= n2:
                return False

            match = i < n1 and (s[i] == p[j] or p[j] == ".")
            # Handles star case
            if (j + 1) < n2 and p[j+1] == "*":
                dp[(i, j)] = ((dfs(i, j + 2)) or  # don't use, it (hence the non-inc i)
                            (match and dfs(i+1, j)))         # use it and we don't increment it because of future use of *
                return dp[(i, j)]

            if match:
                dp[(i, j)] = dfs(i + 1, j + 1)
                return dp[(i, j)]
            # No match
            dp[(i, j)] = False
            return False

       
        return dfs(0, 0)