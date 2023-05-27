from typing import Optional
import queue
class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        que=queue.Queue()
        result=0
        if root == None:
            return result
        que.put(root)
        while not que.empty():
            size=que.qsize()
            result+=1
            for i in range(size):
                node=que.get()
                if node.left:
                    que.put(node.left)
                if node.right:
                    que.put(node.right)
                if not node.left and not node.right:
                    return result
sol=Solution()
root=TreeNode(3)
root.left=TreeNode(9)
root.right=TreeNode(20)
ptr=root.right
ptr.left=TreeNode(15)
ptr.right=TreeNode(7)
print(sol.minDepth(root))
