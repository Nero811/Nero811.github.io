from typing import Optional
import sys

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # 先用遞迴走彷整顆BST，將值存入List
    def travel(self, root, lt):
        if not root:
            return
        lt.append(root.val)
        self.travel(root.left, lt)
        self.travel(root.right, lt)
        return
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        lt = []
        # 先定義result為最大值，也可以用float('inf')
        result = sys.maxsize
        self.travel(root, lt)
        # 排序list (ps. BST如果走訪用中序遍歷，就是排序過後了，不需再用sorted func)
        lt = sorted(lt)
        for i in range(1,len(lt)):
            # 遍歷數組兩兩取最小值
            result = min(result, lt[i] - lt[i - 1])
        
        return result
    
if __name__ == "__main__":
    root = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(6))
    sol = Solution()
    print(sol.getMinimumDifference(root))
