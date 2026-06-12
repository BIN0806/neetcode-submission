class Solution:
    def getSum(self, a: int, b: int) -> int:
        res = 0
        carry = 0
        mask = 0xFFFFFFFF

        for i in range(31):
            a_i, b_i = (a >> i) & 1, (b >> i) & 1
            cur_bit = a_i ^ b_i ^ carry
            carry = (a_i + b_i + carry) >= 2
            if cur_bit:
                res |= (1 << i)
        
        if res > 0x7FFFFFFF:
            res = ~(res ^ mask)

        return res