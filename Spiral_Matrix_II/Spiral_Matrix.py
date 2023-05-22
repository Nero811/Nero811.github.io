# -*- coding: utf-8 -*-
"""
Created on Thu Apr  6 23:03:30 2023

@author: User
"""
from typing import List
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        lt=[[0 for j in range(n)] for i in range(n)]
        lenX=n
        lenY=n
        cnt=0
        Set=0
        y=0
        while cnt<(n*n): 
            for i in range(Set,lenX-Set):     
       #         print('s1')
                cnt+=1
                if cnt>n*n:
                    break
                lt[Set][i]=cnt
       #     print(lt)
            Set+=1
            for j in range(Set,lenY-y):
       #         print('s2')
                cnt+=1
                if cnt>n*n:
                    break
                lt[j][lenX-Set]=cnt    
       #     print(lt)
            for i in range(lenX-Set,Set,-1):
       #         print('s3')
                cnt+=1  
                if cnt>n*n:
                    break
                lt[lenY-Set][i-1]=cnt 
       #     print(lt)
            for j in range(lenY-Set,Set-1,-1):
        #        print('s4')
                cnt+=1
                if cnt>n*n:
                    break
                lt[j][Set-1]=cnt
        #        print(cnt)
        #    print(lt)
            y+=1
        return lt
sol=Solution()
n=5
print(sol.generateMatrix(n))