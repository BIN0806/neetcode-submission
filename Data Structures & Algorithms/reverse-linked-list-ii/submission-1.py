# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        # First-Pass
        dummy = ListNode(0)
        dummy.next = head

        cur = dummy 

        while cur and cur.val < left - 1:
            cur = cur.next

        before_left = cur
        reverse = []
        if before_left:
            cur = before_left.next
        while cur and cur.val <= right:
            reverse.append(cur)
            cur = cur.next

        if before_left and reverse:
            before_left.next = reverse[-1]
            
        for i in range(len(reverse) - 1, 0, -1):
            reverse[i].next = reverse[i-1]
        if reverse:
            reverse[0].next = cur

        return dummy.next
        # Second-Pass



        
