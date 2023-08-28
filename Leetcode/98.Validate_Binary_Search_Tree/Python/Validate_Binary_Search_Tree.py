from typing import Optional

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def travel(self, root, lt):
        """
        中序遍歷TreeNode， 將 Treenode value存入list當中
        """
        if root == None:
            return
        self.travel(root.left, lt)
        lt.append(root.val)
        self.travel(root.right, lt)
        return

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        """
        先得到一個存放所有TreeNode value的list，再去走訪list，
        若前一個數字比後一個大，表示不是Binary Search Tree
        """
        lt = []
        self.travel(root, lt)
        for i in range(1, len(lt)):
            if lt[i - 1] >= lt[i]:
                return False
        
        return True


if __name__ == "__main__":
    root = TreeNode(5)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.right.left = TreeNode(3)
    root.right.right = TreeNode(6)

    # root = TreeNode(2, TreeNode(1), TreeNode(3))
    sol = Solution()
    print(sol.isValidBST(root))