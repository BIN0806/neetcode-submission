# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        res_1 = deque([p])
        res_2 = deque([q])
        while res_1 and res_2:
            node_1, node_2 = res_1.popleft(), res_2.popleft() 
            if node_1 == None and node_2 == None:
                continue 
            if node_1 == None or node_2 == None or node_1.val != node_2.val:
                return False
                
            res_1.append(node_1.left)
            res_1.append(node_1.right)
            res_2.append(node_2.left)
            res_2.append(node_2.right)

        return res_1 == res_2


    