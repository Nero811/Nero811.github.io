from typing import Optional
from typing import List

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def travel(self, root, dic):
        if not root:
            return
        
        self.travel(root.left, dic)
        # 中序遍歷BST ，dic儲存key出現頻率
        if not dic.get(root.val):
            dic[root.val] = 1
        else:
            dic[root.val] += 1
        self.travel(root.right, dic)
        return
        

    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        dic = {}
        self.travel(root, dic)
        maxVal = 0
        result = []
        # 更新maxVal ，val和maxVal相同的key就是答案
        for key,val in dic.items():
            if val > maxVal:
                result.clear()
                maxVal = val
                result.append(key)
            elif val == maxVal:
                result.append(key)
        
        return result


if __name__ == "__main__":
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(2)
    sol = Solution()
    print(sol.findMode(root))