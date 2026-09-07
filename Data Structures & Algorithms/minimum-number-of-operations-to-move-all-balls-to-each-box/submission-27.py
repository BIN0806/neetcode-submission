class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        res = [0] * n

        balls, moves = 0, 0
        for i in range(n):
            print(balls, moves)
            res[i] = moves + balls

            moves = moves + balls 
            balls += int(boxes[i])

        print(res)

        balls, moves = 0, 0
        for i in range(n-1,-1,-1):
            print(balls, moves)
            res[i] = moves + balls

            moves = moves + balls 
            balls += int(boxes[i])

            res[i] += moves      
            
        print(res)

        return res
