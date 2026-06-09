class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows, cols = len(matrix), len(matrix[0])
        # for r in range(rows):
        #     for c in range(cols):
        #         if matrix[r][c] == 0:
        #             for new_c in range(cols):
        #                 matrix[r][new_c] = 0
        #             for new_r in range(rows):
        #                 matrix[new_r][c] = 0
        #             break
        for r in range(rows):
            for c in range(cols):
                if matrix[r][c] == 0:
                    matrix[0][c] = matrix[r][0] = 0
                    # print("DEBUG:")
                    # for row in matrix:
                    #     print(row)
                    # print("~")

        for c in range(cols):    
            if matrix[0][c] == 0:
                for r in range(rows):
                    matrix[r][c] = 0 

        for r in range(rows):
            if matrix[r][0] == 0:
                for c in range(cols):
                    matrix[r][c] = 0 
    
        # 1 0 3
        # 0 0 1 
        # 1 1 1


        