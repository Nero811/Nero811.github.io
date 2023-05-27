from typing import Optional
import queue
class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        que=queue.Queue()
        que.put(root)
        result=0
        while not que.empty():
            size=que.qsize()
            result+=1
            for i in range(size):
                node=que.get()
                if node.left:
                    que.put(node.left)
                if node.right:
                    que.put(node.right)
        return result
root=TreeNode(3)
root.left=TreeNode(9)
root.right=TreeNode(20)
ptr=root.right
ptr.left=TreeNode(15)
ptr.right=TreeNode(7)
sol=Solution()
print(sol.maxDepth(root))
