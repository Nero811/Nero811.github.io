from typing import Optional
import queue


class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        # 沒有找到key，直接返回None
        if not root:
            return None
        # 找到key，且有左右結點
        if root.val == key and root.left and root.right:
            # 宣告cur為左結點，curNext為cur的右結點
            cur = root.left
            curNext = cur.right
            # 若curNext為真就一直像右走訪
            while curNext:
                cur = curNext
                curNext = curNext.right
            # 因BST性質，root.right結點一定大於cur，將root.right插入cur右結點
            cur.right = root.right
            return root.left
        # 找到key，且沒有右結點，返回左結點
        elif root.val == key and root.left and not root.right:
            return root.left
        # 找到key，且沒有左結點，返回右結點
        elif root.val == key and not root.left and root.right:
            return root.right
        # 找到key，且沒有左右結點，返回None直接刪除結點
        elif root.val == key and not root.left and not root.right:
            return None
        
        if root.val > key:
            root.left = self.deleteNode(root.left, key)
        if root.val < key:
            root.right = self.deleteNode(root.right, key)
        
        return root

if __name__ == "__main__":
    root = TreeNode(5, TreeNode(3, TreeNode(2), TreeNode(4)), TreeNode(6))
    root.right.right = TreeNode(7)
    key = 0
    sol = Solution()
    result = sol.deleteNode(root, key)
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