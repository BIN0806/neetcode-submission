# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
def print_ll(head):
    res = []
    while head:
        res.append(head.val)
        head = head.next
    return res
    
class Solution:


    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        left_side, cur = dummy, head
        for _ in range(left - 1):
            left_side, cur = cur, cur.next
        
        print(f"Left side is {left_side.val}")
        print(f"Cur is {cur.val}")


        # print("BEFORE")
        # print("DUMMY: ", print_ll(dummy))
        # print("HEAD:", print_ll(head))
        # print("Left_side:", print_ll(left_side))
        # print("Right_side:", print_ll(cur))

        prev = None 
        for _ in range(right - left + 1):
            temp = cur.next
            cur.next = prev
            prev = cur 
            cur = temp
            print(
                "prev =", (prev.val),
                "cur =", (cur.val),
                "temp =", (temp.val)
            )


        left_side.next.next = cur
        left_side.next = prev
        print("AFTER")
        print(prev.val)
        print("DUMMY: ", print_ll(dummy))
        print("HEAD:", print_ll(head))
        print("Left_side:", print_ll(left_side))
        print("Right_side:", print_ll(cur))
        return dummy.next   



        
