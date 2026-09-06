class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        if n == 0: return [] 

        box = [int(digit) for digit in boxes]

        print(box)
        suffix = [0] * n
        suffix[-1] = boxes[-1]
        for i in range(n-2, -1, -1):
            suffix[i] = suffix[i + 1] + box[i]
        print("SUFFIX", suffix)

        prefix = [0] * n
        prefix[0] = boxes[0]
        for i in range(1, n):
            prefix[i] = prefix[i - 1] + box[i]
        print("PREFIX", prefix)

        res = []
        for i in range(n):
            count = 0
            for j in range(i):
                count += prefix[j] 
            for j in range(n-1, i, -1):
                count += suffix[j]
            res.append(count)
        
        return res
