class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows, cols = len(matrix), len(matrix[0])
        set_zero_rows = set()
        set_zero_cols = set()
        for r in range(rows):
            for c in range(cols):
                if matrix[r][c] == 0:
                    set_zero_rows.add(r)
                    set_zero_cols.add(c)
        
        for row in set_zero_rows:
            for c in range(cols):
                matrix[row][c] = 0
        
        for col in set_zero_cols:
            for r in range(rows):
                matrix[r][col] = 0

        