class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == p or root == q or root == None:
            return root
        
        left = None
        right = None
        if root.val > p.val or root.val > q.val:
            left = self.lowestCommonAncestor(root.left, p ,q)
        if root.val < p.val or root.val < q.val:
            right = self.lowestCommonAncestor(root.right, p ,q)
        
        if left and not right:
            return left
        elif not left and right:
            return right
        elif left and right:
            return root
        elif not left and not right:
            return None

if __name__ == "__main__":
    sol = Solution()
    root = TreeNode(6, TreeNode(2, TreeNode(0), TreeNode(4 ,TreeNode(3), TreeNode(5))), TreeNode(8, TreeNode(7), TreeNode(9)))
    p = root.left
    q = root.left.right
    print(sol.lowestCommonAncestor(root, p ,q).val)