from typing import List
from typing import Optional
import queue

class TreeNode():
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def travel(self, nums, left, right) -> Optional[TreeNode]:
        if left > right:
            return None
        
        mid = (left + right) // 2
        node = TreeNode(nums[mid])
        node.left = self.travel(nums, left, mid - 1)
        node.right = self.travel(nums, mid + 1, right)
        return node
    
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.travel(nums, 0, len(nums) - 1)


if __name__ == "__main__":
    nums = [-10,-3,0,5,9]
    sol = Solution()
    root = sol.sortedArrayToBST(nums)

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