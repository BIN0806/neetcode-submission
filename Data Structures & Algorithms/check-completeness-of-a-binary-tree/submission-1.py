# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        from collections import deque 

        q = deque([root]) 
        seen_none = False
        while q:
            node = q.popleft()

            if node and seen_none:
                return False 

            if not node:
                seen_none = True
                continue

            if node.right and not node.left:
                return False

            q.append(node.left)
            q.append(node.right)

        return True
        