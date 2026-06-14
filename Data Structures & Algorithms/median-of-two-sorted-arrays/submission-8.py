class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums2, nums1 = nums1, nums2
        # make n1 the smaller one 
        # make n2 the bigger one
        n1, n2 = len(nums1), len(nums2)

        total_len = n1 + n2
        half = total_len // 2 

        l, r = 0, n1 - 1
        while True:
            i = (l + r) // 2
            j = half - i - 2


            a_left = nums1[i] if i >= 0 else -float('inf')
            a_right = nums1[i+1] if i+1 < n1 else float('inf')
            b_left = nums2[j] if j >= 0 else -float('inf')
            b_right = nums2[j+1] if j+1 < n2 else float('inf')

            if a_left <= b_right and b_left <= a_right:
                if total_len % 2:
                    return min(a_right, b_right)
                else:
                    return (max(a_left, b_left) + min(a_right, b_right) ) / 2
            elif a_left > b_right:
                r = i - 1
            elif b_left > a_right:
                l = i + 1
            else:
                print("SHOULDN'T HAPPEN")
        # [x_0 | x_1,...]
        # [y_0 | y_1,...]
        # l r 
        
        # x_0 <= y_1
        # y_0 <= x_1
        # [x_0, x_1, y_0, .. ,y_1]
        # 
        
        # [1,2,]
        # [100]
        #  L R
        # [1,2] [3]
        #  l     r

        # [1,2,3]

        # [1], [3,5]


        # [1,4,6] [2, 5]
           
        # [1,4,6,2,5]

        # [1,2,4,5,6]
               
            # the index at which it is inserted 
            # but we can return -1 if not found


        # if len(nums1) < len(nums2):
        #     nums1, nums2 = nums2, nums1
        # n1, n2 = len(nums1), len(nums2)
        # total_len = n1 + n2
        # mid = total_len // 2

        # # finds location of middle element in num1
        # n2_mid = nums2[n2 // 2]

        # l, r = 0, len(num2)  
        # while l < r:
        #     mid = (r+l)//2
        #         if arr[mid] < target:
        #             r = mid - 1
        #         elif arr[mid] > target:
        #             l = mid + 1
        #         else:
        #             return mid
        #     return l 
        #     idx = 

        # if idx + n2_mid < mid:
        #     if n2_mid <= 0:
        #         r 
        #     l += 1
        # elif idx + n2_mid > mid:
        #     if idx >= n2:
        #     r -= 1
        # else: 
        #     return n2_mid





































        # smaller, bigger = (nums1, nums2) if len(nums1) <= len(nums2) else (nums2, nums1)
        # total = len(smaller) + len(bigger)
        # half = total // 2
        
        # l, r = 0, len(smaller) - 1
        # while True:
        #     smaller_ptr = (l + r) // 2
        #     bigger_ptr = half - smaller_ptr - 2

        #     ALeft = nums1[smaller_ptr] if smaller_ptr >= 0 else float("-inf")
        #     ARight = nums1[smaller_ptr+1] if smaller_ptr + 1 < len(nums1) else float("inf")
        #     BLeft = nums2[bigger_ptr] if bigger_ptr >= len(nums2) else float("-inf")
        #     BRight = nums2[bigger_ptr+1] if bigger_ptr + 1 < len(nums2) else float("inf")

        #     # Parition is Right
        #     if ALeft <= BRight and BLeft <= ARight:
        #         if total % 2 == 1:
        #             return min(ARight, ALeft)
        #         return max(ALeft, BLeft) + max(ARight, BRight) / 2                
        #     elif ALeft > BLeft:  
        #         r = smaller_ptr - 1
        #     else:
        #         l = smaller_ptr + 1
        #         # all the same:
                
        # # [1,2,3, 4,5,6]

        # # def search(arr, val):
        #     # l, r = 0, len(arr) - 1
        #     # while l < r:
        #     #     mid = (l + r) // 2
        #     #     if arr[mid] < 
        #     #     elif arr[mid] > :
        #     #         l = mid + 1
        #     #     else:
        # # def median(arr):
        # #     n = len(arr)
        # #     mid = len(arr) // 2
        # #     if n % 2 == 0:
        # #         return (arr[mid] + arr[mid - 1]) // 2
        # #     else:
        # #         return arr[mid]

        # # n1, n2 = len(nums1), len(nums2)
        # # if not n1 and not n2:
        # #     return 0 
        # # elif (not n1):
        # #     return median(nums2)
        # # elif (not n2):
        # #     return median(nums1)

        # # median1 = median([1,2,3,4,5])
        # # median2 = median([1,2,3,4])
        # # print(median1)
        # # print(median2)
        # # return 0.0
        # # else:
        # # if right is outerbound:
        # #     move right ptr
        # # if OOB < 0:
        # #     left_most

        # # if OOB > n:
        # #     right_most
        
        # # return (left_most + right_most) / 2 

        # # [1, 2]
        # # [3, 4]

        # # [1, 2, 4]
        # # [5, 5, 5]
        
        # # [1 ,2, 4, 5]
        # # [3]