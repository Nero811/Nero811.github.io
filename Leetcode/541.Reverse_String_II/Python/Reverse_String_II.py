# -*- coding: utf-8 -*-
"""
Created on Tue Jul 25 22:00:27 2023

@author: Jack Yang
"""
from typing import List

class Solution:
    def reverse(self, s: List[str], start: int, k: int) -> str:
        end = (start + k) - 1
        while start < end:
            s[start], s[end] = s[end], s[start]
            start+=1
            end-=1
        return "".join(s)
        
    def reverseStr(self, s: str, k: int) -> str:
        sol = Solution()
        for i in range(0,len(s),2 * k):
            if i + k > len(s) and i != len(s) - 1:
                s = sol.reverse(list(s), i, len(s) - i)
            elif i + k <= len(s):
                s = sol.reverse(list(s), i, k)
        return s

sol = Solution()
#s = "abcdefg"
#k = 2
#s = "abcd"
#k = 4
#s = "abcdefg"
#k = 8
s = "abcdefg"
k = 3
print(sol.reverseStr(s, k))
    
            