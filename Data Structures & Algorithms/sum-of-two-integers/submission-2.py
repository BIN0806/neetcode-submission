class Solution:
    def getSum(self, a: int, b: int) -> int:
        res = 0
        carry = 0

        # Python integers can be represnted as negative so this handles itself (-4) + (3) = 3 - 4
        for i in range(32):
            # gets the ith bit
            a_i, b_i = (a >> i) & 1, (b >> i) & 1

            # what is the cur_bit, includes carry if were prev incremented
            cur_bit = a_i ^ b_i ^ carry

            # do we have enough for a carry in our cur_bit?
            carry = (a_i + b_i + carry) >= 2

            if cur_bit:
                res |= (1 << i) # set the ith digit to 1, else leave as 0 
        
        # If Negative =>
        # 0x8xxxxxxx
        # => Get all the 0's
        if res & 0x80000000:
            res -= 0x100000000

        return res