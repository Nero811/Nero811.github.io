# -*- coding: utf-8 -*-
"""
Created on Wed Jul 26 18:32:22 2023

@author: Jack Yang
"""
from typing import List

class Solution:
    def compareHash(self, hashTable: List[int], hashTable2: List[int]) -> List[int]:
        for i in range(26):
            if hashTable[i] or hashTable2[i] > 0:
                hashTable[i] = min(hashTable[i], hashTable2[i])
        
        return hashTable
        
    def commonChars(self, words: List[str]) -> List[str]:
        hashTable = [0,] * 26
        for j in words[0]:
            hashTable[ord(j) - 97] += 1
            
        for i in range(1,len(words)):
            hashTable2 = [0,] * 26
            for word in words[i]:
                hashTable2[ord(word) - 97] += 1
                
            hashTable = self.compareHash(hashTable, hashTable2)
        
        result = []
        for num in range(26):
            while hashTable[num] > 0:
                result.append(chr(num + 97))
                hashTable[num] -= 1
        
        return result

sol = Solution()
words = ["bella","label","roller"]
print(sol.commonChars(words))
                    
                
            