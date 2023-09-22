from typing import Optional
from typing import List
import queue

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:       
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if len(postorder) == 0:
            return None

        root = TreeNode(postorder[len(postorder) - 1])
        if len(postorder) == 1:
            return root
        postorder = postorder[:len(postorder) - 1:]
        index = 0
        for i in range(len(inorder)):
            if inorder[i] == root.val:
                index = i
                break
        leftInorder = inorder[:index:]
        rightInorder = inorder[index + 1::]

        leftPostorder = postorder[:index:]
        rightPostorder = postorder[index::]

        root.left = self.buildTree(leftInorder, leftPostorder)
        root.right = self.buildTree(rightInorder, rightPostorder)
        return root

if __name__ == "__main__":
    sol = Solution()
    #inorder = [9,3,15,20,7]
    #postorder = [9,15,7,20,3]
    inorder = [3,2,1]
    postorder = [3,2,1]
    root = sol.buildTree(inorder, postorder)
    que = queue.Queue()
    que.put(root)
    while not que.empty():
        size = que.qsize()
        for i in range(size):
            node = que.get()
            print(node.val)
            if node.left:
                que.put(node.left)
            if node.right:
                que.put(node.right)

