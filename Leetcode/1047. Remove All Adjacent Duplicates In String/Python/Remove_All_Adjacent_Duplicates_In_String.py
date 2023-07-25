# -*- coding: utf-8 -*-
"""
Created on Tue Jul 25 21:45:46 2023

@author: Jack Yang
"""

class Solution:
    def removeDuplicates(self, s: str) -> str:
        st = []
        for i in range(len(s)):
            if len(st) != 0 and s[i] == st[-1]:
                st.pop()
                continue
            st.append(s[i])
        
        result=""
        for c in st:
            result+=c
        
        return result

#s = "abbaca"
s = "azxxzy"
sol = Solution()
print(sol.removeDuplicates(s))
            