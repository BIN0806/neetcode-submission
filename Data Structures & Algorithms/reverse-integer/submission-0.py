class Solution:
    def reverse(self, x: int) -> int:
        pos = True
        if x < 0:
            pos = False
        x = abs(x)
        x = int(str(x)[::-1])
        print(x)
        
        if -2 ** 31 <= x <= 2 ** 31 - 1:
            # print(x)
            if pos:
                return x
            else:
                return -x
        else:
            return 0