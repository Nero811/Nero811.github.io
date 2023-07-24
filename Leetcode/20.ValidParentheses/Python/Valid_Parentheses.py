# -*- coding: utf-8 -*-
"""
Created on Mon Jul 24 21:11:10 2023

@author: Jack Yang
"""

class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 1:
            return False
        
        st=[]
        for i in range(len(s)):
            if len(st) != 0:
                if s[i] == ')':
                    if st[-1]== '(':
                        st.pop()
                        continue
                    else:
                        return False
                elif s[i] == ']':
                    if st[-1] == '[':
                        st.pop()
                        continue
                    else:
                        return False
                elif s[i] == '}':
                    if st[-1] == '{':
                        st.pop()
                        continue
                    else:
                        return False
            st.append(s[i])
        
        if len(st) != 0:
            return False
    
        return True


sol = Solution()
#s="()[]{}"
s=")(){}"
print("True")if sol.isValid(s) == True else print("False")