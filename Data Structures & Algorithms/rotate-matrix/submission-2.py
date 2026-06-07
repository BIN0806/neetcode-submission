class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        # [[1,2],
        #  [3,4]]
        n = len(matrix)
        for layer in range(n):
            first, last = layer, n - 1 - layer

            for i in range(first, last):
                offset = i - first

                # store top-left 
                temp = matrix[first][offset]

                # top-left = bottom-left
                matrix[first][offset] = matrix[last - offset][first]

                # bottom-left = bottom-right
                matrix[last - offset][first] = matrix[last][last - offset]

                # bottom-right = top-right
                matrix[last][last-offset] = matrix[offset][last]

                # top-right = (which is temp) bottom-left
                matrix[offset][last] = temp
        
        # # 180 on Matirx 
        # matrix.reverse()
        # # Transpose
        # for i in range(len(matrix)):
        #     for j in range(i+1, len(matrix)):
        #         matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]




     