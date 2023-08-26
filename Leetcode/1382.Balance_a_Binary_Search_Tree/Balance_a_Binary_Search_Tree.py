from typing import List
import queue

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def travel(self, root, lt: List):
        if root == None:
            return
        self.travel(root.left, lt)
        lt.append(root)
        self.travel(root.right, lt)

    def makeTree(self, lt, left, right):
        if left > right:
            return None
        
        mid = (left + right) // 2
        root = lt[mid]
        root.left = self.makeTree(lt, left, mid - 1)
        root.right = self.makeTree(lt, mid + 1, right)
        return root

    def balanceBST(self, root: TreeNode) -> TreeNode:
        lt = []
        self.travel(root, lt)
        result = self.makeTree(lt, 0, len(lt) - 1)

        return result
    
if __name__ == "__main__":
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.right = TreeNode(3)
    root.right.right.right = TreeNode(4)
    sol = Solution()
    result = sol.balanceBST(root)
    que = queue.Queue()
    if result:
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


