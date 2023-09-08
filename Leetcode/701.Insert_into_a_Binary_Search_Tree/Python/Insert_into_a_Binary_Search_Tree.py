from typing import Optional
import queue

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def travel(self, root, val) -> TreeNode:
        if root == None:
            return TreeNode(val)
        if root.val > val:
            root.left = self.travel(root.left, val)
        if root.val < val:
            root.right = self.travel(root.right, val)
        return root

    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        return self.travel(root, val)


if __name__ == "__main__":
    root = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7))
    sol = Solution()
    val = 5
    result = sol.insertIntoBST(root, 5)
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
