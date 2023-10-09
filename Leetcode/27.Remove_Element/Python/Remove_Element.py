# -*- coding: utf-8 -*-
"""
Created on Wed Apr  5 13:58:07 2023

@author: User
"""
from typing import List
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        fastidx=0
        slowidx=0
        while fastidx <= len(nums)-1:
            if nums[fastidx]!=val:
                nums[slowidx]=nums[fastidx]
                slowidx+=1
            fastidx+=1
        return slowidx
nums=[3,2,2,3]
#nums=[0,1,2,2,3,0,4,2]
val=3
#val=2
sol=Solution()
print(sol.removeElement(nums, val))
print(nums)

                