from typing import Optional
import queue


class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def travel(self, root1, root2) -> TreeNode:
        if root1 == None or root2 == None:
            if root1 and root2 == None:
                return root1
            elif root1 == None and root2:
                return root2
            else:
                return None
        newRoot = TreeNode(root1.val + root2.val)
        newRoot.left = self.travel(root1.left, root2.left)
        newRoot.right = self.travel(root1.right, root2.right)
        return newRoot

    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.travel(root1, root2)


if __name__ == "__main__":
    root1 = TreeNode(1, TreeNode(3, TreeNode(5)), TreeNode(2))
    root2 = TreeNode(2, TreeNode(1), TreeNode(3))
    root2.left.right = TreeNode(4)
    root2.right.right = TreeNode(7)
    sol = Solution()
    result = sol.mergeTrees(root1, root2)
    que = queue.Queue()
    que.put(result)
    while not que.empty():
        size = que.qsize()
        for i in range(size):
            node = que.get()
            print(node.val)
            if node.left:
                que.put(node.left)
            if node.right:
                que.put(node.right)
