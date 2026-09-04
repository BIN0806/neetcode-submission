        
class Solution:
    def findKthNumber(self, n: int, k: int) -> int:        
        def count_prefix(x):
            count = 0 
            first, last = x, x + 1
            while first <= n:
                count += min(n + 1, last) - first
                first *= 10
                last *= 10
            return count

        
        k -= 1
        ptr = 1
        while k:
            count = count_prefix(ptr)
            if k < count:
                ptr *= 10
                k -= 1
            else:
                ptr += 1
                k -= count
        return ptr 