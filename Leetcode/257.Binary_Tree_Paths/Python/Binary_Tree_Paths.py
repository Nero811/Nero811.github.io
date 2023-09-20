from typing import Optional
from typing import List

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.result = []

    def travel(self, root, path):
        if not root:
            return
        # 沒有左右子樹表示找到葉子節點
        if not root.left and not root.right:
            path += str(root.val)
            self.result.append(path)
            return
        # 回朔技巧
        path += str(root.val)
        path += "->"
        self.travel(root.left, path)
        self.travel(root.right, path)
        return
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        self.travel(root, "")
        return self.result

if __name__ == "__main__":
    sol = Solution()
    root = TreeNode(1, TreeNode(2), TreeNode(3))
    root.left.right = TreeNode(5)
    print(sol.binaryTreePaths(root))