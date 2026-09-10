class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        q = deque([ (i, t) for i, t in enumerate(tickets)])
        count = 0
        while q:
            # print(q)
            i, t = q.popleft()
            if t == 0:
                continue 

            if i == k and t == 1:
                return count + 1

            count += 1
            q.append((i, t - 1))
        return -1