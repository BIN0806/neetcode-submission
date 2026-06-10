class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        n1, n2 = len(num1), len(num2)
        res = [0] * (n1 + n2)

        for i1 in range(n1):
            for i2 in range(n2):
                digit = int(num1[i1]) * int(num2[i2])

                res[i1+i2] += digit
                res[i1+i2+1] += res[i1+i2] // 10
                res[i1+i2] = res[i1+i2] % 10

        res, beg = res[::-1], 0
        while beg < len(res) and res[beg] == 0:
            beg += 1

        res = map(str, res[beg:])
        return "".join(res)
    #     def add(n1, n2):
    #         result = ""
    #         carry = 0
    #         n1 = n1 if len(n1) >= len(n2) else n2
    #         for i in range(len(n1)):
    #             if i <= int(n2):
    #                 summed = int(n1[i]) + int(n2[i]) + carry
    #                 carry = summed // 10
    #                 result = str(summed % 10) + result
    #                 # print("=====")
    #                 # print(summed)
    #                 # print(carry)
    #                 # print(result)
    #                 # print("~~~~")
    #             else:
    #                 result += n1[i]
    #         if carry:
    #             result = "1" + result

    #         return result

    #     if not(len(num1) > len(num2)):
    #         num1, num2 = num2, num1

    #     result = ""
    #     for i in range(len(num2)):
    #         print(f"{result} + {num1 * int(num2[len(num2)-i-1] + "0" * i)} = ")
    #         result = add(result, num1 * int(num2[len(num2)-i-1] + "0" * i))
    #         print(f"{result}")
    # #     result = num1[len(num2):num1] + result
    #     return result 