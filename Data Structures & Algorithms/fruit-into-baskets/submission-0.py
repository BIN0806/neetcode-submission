from collections import Counter 


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        count = Counter(fruits)
        i, sum = 0, 0

        for k, v in count.most_common():
            sum += v
            i += 1    
            if i == 2:
                return sum 
        return sum