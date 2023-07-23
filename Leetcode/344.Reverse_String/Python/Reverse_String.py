# -*- coding: utf-8 -*-
"""
Created on Sun Jul 23 21:18:11 2023

@author: Jack Yang
"""
from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        i = 0
        j = len(s) - 1
        while i < j:
            s[i],s[j] = s[j],s[i]
            i+=1
            j-=1

s = ["h","e","l","l","o"]
sol = Solution()
print(sol.reverseString(s))