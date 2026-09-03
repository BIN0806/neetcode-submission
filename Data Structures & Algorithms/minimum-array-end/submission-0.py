class Solution:
    def minEnd(self, n: int, x: int) -> int:

        # n = 4, x = 2

        # res = [x]
        # ith_bit = 2
        # base_line = 0010

        # while 010 & 010 
        
        xth_bit = 1
        nth_bit = 1 
        answer = x
        while nth_bit <= n - 1:
            if xth_bit & x == 0:
                if nth_bit & (n-1) != 0:
                    answer = answer | xth_bit
                nth_bit <<= 1
            xth_bit <<= 1
        return answer
 