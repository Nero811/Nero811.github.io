# -*- coding: utf-8 -*-
"""
Created on 2023-07-27

@author: Jack Yang

Description
"""
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        que = []
        if root == None:
            return root
        
        que.append(root)
        
        while len(que) > 0:
            size = len(que)
            for i in range(size):
                node = que.pop(0)
                if node.left != None:
                    que.append(node.left)
                if node.right != None:
                    que.append(node.right)
                node.left, node.right = node.right, node.left
        
        return root
    
root = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7, TreeNode(6), TreeNode(9)))
sol = Solution()
result = sol.invertTree(root)
que = []
if result != None:
    que.append(result)

while len(que) > 0:
    size = len(que)
    for i in range(size):
        node = que.pop(0)
        print(node.val)
        if node.left != None:
            que.append(node.left)
        if node.right != None:
            que.append(node.right)


         