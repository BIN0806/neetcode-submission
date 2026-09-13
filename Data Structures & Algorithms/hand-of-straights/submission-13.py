class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        from collections import Counter, defaultdict, deque

        if len(hand) % groupSize != 0:
            return False

        freq = Counter(hand)
        # Input: hand = [1,2,4,2,3,5,3,4], groupSize = 4
        for num in hand:
            # print(sorted(freq.items()))
            start = num 
            if freq[num] == 0:
                continue
            while freq[start-1]:
                start -= 1
            # print(num, "->", start)
            # print("(", start, ",", start + groupSize - 1, ")")
            while start <= num:
                while freq[start]:
                    for i in range(start, start + groupSize):
                        if freq[i] == 0:
                            return False 
                        freq[i] -= 1
                start += 1
        
        return True 
            