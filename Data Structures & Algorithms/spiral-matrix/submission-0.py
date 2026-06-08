class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # row, col = len(matrix), len(matrix[0])
        
        # result = []
        # col_stop = col
        # row_stop = row
        # i = 0
        # while i < col // 2:
        #     r = c = 0 

        #     # topleft -> topright
        #     while c < col_stop:
        #         result.append(matrix[r][c])
        #         c += 1
        #     col_stop -= 1

        #     # topright -> botright

        #     while r < row_stop:
        #         result.append(matrix[r][c])
        #         r += 1
        #     row_stop -= 1


        #     # botright -> botleft
        #     while c > 0:
        #         result.append(matrix[r][c])
        #         c -= 1

        #     # botleft -> topleft
        #     while r > 0:
        #         result.append(matrix[r][c])
        #         r -= 1

        #     i += 1

        # return result

        row, col = len(matrix), len(matrix[0])
        result = []
        left, right = 0, col
        top, bottom = 0, row

        while left < right and top < bottom:

            # topleft -> topright
            for c in range(left, right):
                result.append(matrix[top][c])
            top += 1 # finished the top row

            # topright -> botright
            for c in range(top, bottom):
                result.append(matrix[c][right - 1]) #right needs to be 0-indexed
            right -= 1 # finished the right col

            if not (left < right and top < bottom):
                break # we have to check here for certain edge cases

            # botright -> botleft
            # avoid duplicate of right by -1 
            # to include left sub by -1
            for c in range(right - 1, left - 1, -1):
                result.append(matrix[bottom-1][c]) # another off by 1
            bottom -= 1 # finished so shift up

            # botleft -> topleft
            for r in range(bottom - 1, top - 1, -1): # off by 1 twice
                result.append(matrix[r][left])
            left += 1

        return result





        # 1, 2, 3
        # 4, 5, 6
        # 7, 8, 9