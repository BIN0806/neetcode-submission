class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        from collections import Counter, defaultdict, deque

        hand.sort()
        n = len(hand)
        freq = Counter(hand)
        q = deque

# Input: hand = [1,2,4,2,3,5,3,4], groupSize = 4

        for num in hand:
            # print(sorted(freq.items()))
            if freq[num] == 0:
                continue
            for i in range(num, num + groupSize):
                if freq[i] == 0:
                    # print(i)
                    return False 
                freq[i] -= 1
        
        return True 
            