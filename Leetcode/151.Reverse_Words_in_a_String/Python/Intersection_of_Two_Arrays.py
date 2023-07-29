# -*- coding: utf-8 -*-
"""
Created on 2023-07-28

@author: Jack Yang

Description: 349. Intersection of Two Arrays
"""
from typing import List

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
            dic = {}
            result = []
            for i in nums1:
                dic[i] = 1
            for j in nums2:
                if j in dic and result.count(j) == 0:
                    result.append(j)
            return result

sol = Solution()
#nums1 = [1,2,2,1]
#nums2 = [2,2]
nums1 = [4,9,5]
nums2 = [9,4,9,8,4]
print(sol.intersection(nums1, nums2))
            
            
