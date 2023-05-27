from typing import Optional,List
import queue
class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        lt=[]
        if root == None:
            return lt
        que=queue.Queue(10001)
        que.put(root)
        while not que.empty():
            size=que.qsize()
            Max=-2147483649
            for i in range(size):
                node=que.get()
                Max=max(Max,node.val)
                if node.left:
                    que.put(node.left)
                if node.right:
                    que.put(node.right)
            lt.append(Max)
        return lt

root=TreeNode(1)
root.left=TreeNode(3)
root.right=TreeNode(2)
ptr=root.left
ptr.left=TreeNode(5)
ptr.right=TreeNode(3)
ptr=root.right
ptr.right=TreeNode(9)
sol=Solution()
result=sol.largestValues(root)
for i in result:
    print(i)
