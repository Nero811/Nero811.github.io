from typing import Optional
import queue
class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root.left==None and root.right==None:
            return True
        que1=queue.Queue()
        que2=queue.Queue()
        que1.put(root.left)
        que2.put(root.right)
        while not que1.empty() or not que2.empty():
            size1=que1.qsize()
            size2=que2.qsize()
            if size1 != size2:
                return False
            for _ in range(size1):
                node1=que1.get()
                node2=que2.get()
                if node1.left:
                    que1.put(node1.left)
                if node1.right:
                    que1.put(node1.right)
                if node2.right and node1.left and (node2.right.val==node1.left.val):
                    que2.put(node2.right)
                elif node2.right and node1.left==None:
                    return False
                if node2.left and node1.right and (node2.left.val==node1.right.val):
                    que2.put(node2.left)
                elif node2.left and node1.right==None:
                    return False
        return True

sol=Solution()
root=TreeNode(1)
ptr=root
ptr.left=TreeNode(2)
ptr.right=TreeNode(2)
#ptr.left.left=TreeNode(3)
ptr.left.right=TreeNode(3)
#ptr.right.left=TreeNode(4)
ptr.right.right=TreeNode(5)
print("True") if sol.isSymmetric(root)==True else print("False")
