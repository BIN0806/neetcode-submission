class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        res = [0] * n

        balls, moves = 0, 0
        for i in range(1, n):
            print(balls, moves)
            if boxes[i] == "1":
                balls += 1 
            if res[i-1] != 0:
                moves = moves + balls 
            res[i] += moves

        print(res)

        balls, moves = 0, 0
        for i in range(n-2,-1,-1):
            print(balls, moves)
            if boxes[i] == "1":
                balls += 1 
            if res[i-1] != 0:
                moves = moves + balls 
            res[i] += moves      
            
        print(res)

        return res
