class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        target = tickets[k]
        count = 0

        for i, t in enumerate(tickets):
            if i <= k:
                count += min(t, target)
            else:
                count += min(t, target - 1)

        return count