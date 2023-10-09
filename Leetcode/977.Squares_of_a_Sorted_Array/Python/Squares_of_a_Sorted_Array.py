# -*- coding: utf-8 -*-
"""
Created on Wed Apr  5 14:53:41 2023

@author: User
"""
from typing import List
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            nums[i]*=nums[i]
        result=sorted(nums)
        return result
nums = [-4,-1,0,3,10]
sol=Solution()
print(sol.sortedSquares(nums))