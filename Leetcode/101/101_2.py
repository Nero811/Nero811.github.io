from typing import Optional
import queue
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def Solution(self,root1: Optional[TreeNode],root2: Optional[TreeNode]) -> bool:
        if not root1 and not root2:
            return True
        elif not root1 or not root2 or root1.val!=root2.val:
            return False
        if self.Solution(root1.left,root2.right)==False:
            return False
        if self.Solution(root1.right,root2.left)==False:
            return False
        return True
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.Solution(root.left,root.right)
sol=Solution()
root=TreeNode(1)
ptr=root
ptr.left=TreeNode(2)
ptr.right=TreeNode(2)
#ptr.left.left=TreeNode(3)
ptr.left.right=TreeNode(3)
#ptr.right.left=TreeNode(4)
ptr.right.right=TreeNode(3)
print("True") if sol.isSymmetric(root)==True else print("False")

