class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        from collections import defaultdict
        import heapq
        import math
        adj_list = defaultdict(list)

        minHeap = []
        for i, (x1, y1) in enumerate(points):
            for j, (x2, y2) in enumerate(points):
                if x1 == x2 and y1 == y2:
                    continue 
                    
                heapq.heappush((abs(x1-x2) + abs(y1-y2), (i, j)))
        
        connected = set()
        min_sum = 0
        while minHeap:
            dist, i, j = heapq.heappop(minHeap)
            if i in connected and j in connected:
                continue

            connected.add(i)
            connected.add(j)
        
            min_sum += dist

        return ans 