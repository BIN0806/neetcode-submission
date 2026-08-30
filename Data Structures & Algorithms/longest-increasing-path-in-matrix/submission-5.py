class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n, m = len(matrix), len(matrix[0])
        dp = [ [1] * m for _ in range(n)]
        from collections import deque 
        q = deque()

        def out_of_bounds(r, c):
            if r >= n or c >= m or r < 0 or c < 0:
                return True

        def update(r, c):
            DIR = [(-1, 0), (0, -1), (0, 1), (1,0)]
            original = matrix[r][c]

            for dx, dy in DIR:
                if out_of_bounds(r+dx, c+dy): 
                    continue

                directional_value = matrix[r+dx][c+dy]

                if original > directional_value and 1 + dp[r][c] > dp[r+dx][c + dy]:
                    dp[r+dx][c + dy] = 1 + dp[r][c]
                    q.append((r+dx, c+dy))


        for r in range(n):
            for c in range(m):
                q.append((r, c))

        while q:
            r, c = q.popleft()
            update(r, c)

        # print(f"DEBUG:")
        # for r in dp:
        #     print(r)
        
        return max([max([val for val in r]) for r in dp])