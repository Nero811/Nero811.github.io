from typing import Optional

class TreeNode:
    def __init__(self,val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    result = 0
    def solution(self, node: TreeNode, path: str) -> TreeNode:
        if node == None:
            return None
        path += str(node.val)
        left = self.solution(node.left, path)
        right = self.solution(node.right, path)
        if left == None and right == None:
            self.result += int(path)
        return node

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.solution(root, "")
        return self.result

sol = Solution()
root = TreeNode(4, TreeNode(9, TreeNode(5), TreeNode(1)), TreeNode(0))
print(sol.sumNumbers(root))

    

