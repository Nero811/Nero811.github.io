from typing import Optional

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        que = []
        que.append(root)
        result = 0
        while len(que) > 0:
            size = len(que)
            for i in range(len(que)):
                node = que.pop()
                result += 1
                if node.left != None:
                    que.append(node.left)
                if node.right != None:
                    que.append(node.right)
        
        return result
    
root = TreeNode(1 , TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3, TreeNode(6)))
sol = Solution()
print(sol.countNodes(root))
        