from typing import Optional
import queue

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        que = queue.Queue()
        if root:
            que.put(root)
        
        result = 0
        while not que.empty():
            size = que.qsize()
            for i in range(size):
                node = que.get()
                if node.left:
                    """
                    找尋左子結點，且為葉子結點
                    """
                    if node.left.left == None and node.left.right == None:
                        result += node.left.val
                    que.put(node.left)
                if node.right:
                    que.put(node.right)
        
        return result

if __name__ == "__main__":
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    sol = Solution()
    print(sol.sumOfLeftLeaves(root))