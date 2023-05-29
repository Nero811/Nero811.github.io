# -*- coding: utf-8 -*-
"""
Created on Wed Apr  5 13:15:30 2023

@author: User
"""
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i=0
        j=len(nums)-1
        mid=0
        while i<=j:
            mid=(i+j)//2
            if nums[mid]==target:
                return mid
            if target > nums[mid]:
                i = mid+1
            elif target < nums[mid]:
                j = mid-1
        return -1
    
sol=Solution()
nums=[-1,0,3,5,9,12]
#target=9
target=2
print(sol.search(nums, target))