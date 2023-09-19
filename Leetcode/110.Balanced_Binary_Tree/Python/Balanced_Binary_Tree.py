from typing import Optional

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = 0
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.balance = True

    def travel(self, root, depth) -> int:
        if not root:
            return depth        
        depth += 1
        # 紀錄左子樹深度
        left = self.travel(root.left, depth)
        # 紀錄右子樹深度
        right = self.travel(root.right, depth)
        # 左子樹深度和右子樹深度絕對值 > 1 表示不平衡
        if abs(left - right) > 1:
            self.balance = False
        # 返回左子樹與右子樹最大的深度
        return max(left, right)        
    
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.travel(root, 0) 
        return self.balance

if __name__ == "__main__":
    sol = Solution()
    root = TreeNode(1, TreeNode(2, TreeNode(3, TreeNode(4), TreeNode(4)), TreeNode(3)), TreeNode(2))
    # root = TreeNode(1)
    # root.left = TreeNode(2)
    # root.left.left = TreeNode(3)
    # root.left.left.left = TreeNode(4)
    # root.left.left.left.left = TreeNode(5)
    print(sol.isBalanced(root))