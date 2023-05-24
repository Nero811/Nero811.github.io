# -*- coding: utf-8 -*-
"""
Created on Thu Apr 20 23:46:27 2023

@author: User
"""

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic=[0]*26
        if len(s)!=len(t):
            return False
        for i in range(len(s)):
            dic[ord(s[i])-ord('a')]+=1;
        for i in range(len(t)):
            if dic[ord(t[i])-ord('a')]<1:
                return False
            else:
                dic[ord(t[i])-ord('a')]-=1;
        return True
sol=Solution()
s='anagram'
t='nagaram'
if sol.isAnagram(s, t):
    print('true')
else:
    print('false')
    
            
        
        
        
        