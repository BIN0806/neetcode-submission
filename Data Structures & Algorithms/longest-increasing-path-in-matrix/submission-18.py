class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        # n, m = len(matrix), len(matrix[0])
        # dp = [ [1] * m for _ in range(n)]
        # parent = [ [ None for _ in range(m)] for _ in range(n)]

        # from collections import deque 
        # q = deque()

        # def out_of_bounds(r, c):
        #     if r >= n or c >= m or r < 0 or c < 0:
        #         return True

        # def update(r, c):
        #     DIR = [(-1, 0), (0, -1), (0, 1), (1,0)]
        #     original = matrix[r][c]

        #     for dx, dy in DIR:
        #         if out_of_bounds(r+dx, c+dy): 
        #             continue

        #         directional_value = matrix[r+dx][c+dy]

        #         if original < directional_value and 1 + dp[r][c] > dp[r+dx][c + dy]:
        #             dp[r+dx][c+dy] = 1 + dp[r][c]
        #             q.append((r+dx, c+dy))
        #             parent[r+dx][c+dy] = (r, c)
        # nums = []
        # for r in range(n):
        #     for c in range(m):
        #         nums.append((r, c))
        # q = deque(sorted(nums, key=lambda x: matrix[x[0]][x[1]]))

        # while q:
        #     r, c = q.popleft()
        #     update(r, c)

        # best = max( ((r,c) for r in range(n) for c in range(m)), key=lambda x: dp[x[0]][x[1]])
        
        # path = []
        # cur = best
        # while cur:
        #     path.append(matrix[cur[0]][cur[1]])
        #     cur = parent[cur[0]][cur[1]]
            
        # print(f"DEBUG:")
        # for r in dp:
        #     print(r)

        # path.reverse()
        # print(path)


        # return dp[best[0]][best[1]]

        ROWS, COLS = len(matrix), len(matrix[0])
        dp = {}     
        DIR = [(-1,0),(1,0),(0,-1),(0,1)]
        def out_of_bounds(r, c):
            if r >= ROWS or c >= COLS or r < 0 or c < 0:
                return True

        def dfs(r, c, path):
            if out_of_bounds(r, c) or (path and path[-1] >= matrix[r][c]):
                return -1

            if (r,c) in dp:
                return dp[(r, c)][0]
                # because if we seen the cell already it has done it's best, defintition of dp
                # to make it more clear we have solved the longest lenght it has donw alreayd?

            res = 1
            for dx, dy in DIR:
                nr, nc = r+dx, c+dy
                path_len = 1 + dfs(nr, nc, path + [matrix[r][c]])
                if path_len > res:
                    res = max(res, path_len)
                    dp[(r, c)] = (res, path + [matrix[r][c]])
            return res

        for r in range(ROWS):
            for c in range(COLS):
                dfs(r, c, []) # each cell is len 1

        print(f"DEBUG:")
        for r in dp:
            print(r)

        # cur = max(dp.values())[1][1]
        # while cur is not None:
        #     path.append(cur)
        # print(path)
        return max(dp.values())[0]

