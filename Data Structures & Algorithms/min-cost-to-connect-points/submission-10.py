class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        import math
        n, node, edges, res = len(points), 0, 0, 0

        dist = [math.inf] * n
        visit = [False] * n

        while edges < n - 1:
            visit[node] = True 
            nextNode = -1
            for i in range(n):
                if visit[i]:
                    continue 

                curDist = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1])
                dist[i] = min(dist[i], curDist)
                if nextNode == -1 or dist[i] < dist[nextNode]:
                    nextNode = i

            res += dist[nextNode]
            node = nextNode 
            edges += 1

        return res 