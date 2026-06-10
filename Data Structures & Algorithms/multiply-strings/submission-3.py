class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        # "3"
        # "4" 
        # "12"


        # "5"
        # "10"
        # 50

        #   12 
        # x 12
        # ----
        #   24
        # +120
        # ----
        #  144
        
        #   99
        # x 99
        # ----
        # 9801

        # O(m*n)
        # O(m + n)

        if num1 == "0" or num2 == "0": return "0"
        n1, n2 = len(num1), len(num2)
        result = [0] * (n1 + n2)

        num1, num2 = num1[::-1], num2[::-1]

        for i1 in range(n1):
            for i2 in range(n2):
                product = int(num1[i1]) * int(num2[i2])

                result[i1+i2] += product
                result[i1+i2+1] += result[i1+i2] // 10
                result[i1+i2] = result[i1+i2] % 10
        print("POST", result)
        result = result[::-1]
        print("REVERSE", result)
        begin = 0
        n = len(result)
        while begin < n and result[begin] == 0 :
            begin += 1
        print("BEGIN", begin)
        result = result[begin:]
        print("RESULT")

        result = map(str, result)

        return "".join(result)