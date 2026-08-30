class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n, m = len(matrix), len(matrix[0])
        dp = [ [1] * m for _ in range(n)]
        parent = [ [ None for _ in range(m)] for _ in range(n)]

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

                if original < directional_value and 1 + dp[r][c] > dp[r+dx][c + dy]:
                    dp[r+dx][c+dy] = 1 + dp[r][c]
                    q.append((r+dx, c+dy))
                    parent[r+dx][c+dy] = (r, c)
        nums = []
        for r in range(n):
            for c in range(m):
                nums.append((r, c))
        q = deque(sorted(nums, key=lambda x: matrix[x[0]][x[1]]))

        while q:
            r, c = q.popleft()
            update(r, c)

        best = max( ((r,c) for r in range(n) for c in range(m)), key=lambda x: matrix[x[0]][x[1]])
        path = []

        cur = best
        while cur:
            path.append(matrix[cur[0]][cur[1]])
            cur = parent[cur[0]][cur[1]]
        print(f"DEBUG:")
        for r in dp:
            print(r)

        path.reverse()
        print(path)


        return dp[best[0]][best[1]]


