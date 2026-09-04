# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head

        cur = dummy
        nodes = []

        # Move to the node immediately before `left`
        for _ in range(left - 1):
            cur = cur.next

        before_left = cur

        # Collect nodes from left through right
        cur = cur.next
        for _ in range(right - left + 1):
            nodes.append(cur)
            cur = cur.next

        # Connect previous part to reversed portion
        before_left.next = nodes[-1]

        # Reverse the connections
        for i in range(len(nodes) - 1, 0, -1):
            nodes[i].next = nodes[i - 1]

        # Connect reversed portion to remaining list
        nodes[0].next = cur

        return dummy.next



        
