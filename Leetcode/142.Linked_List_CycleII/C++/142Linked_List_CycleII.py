# -*- coding: utf-8 -*-
"""
Created on Tue Apr 18 22:55:25 2023

@author: User
"""
from typing import Optional
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None
         
class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        hashTable={}
        dummyhead=ListNode(-10001)
        dummyhead.next=head
        ptr=dummyhead.next
        while ptr!=None:
            if ptr in hashTable and hashTable[ptr]==1:
                return ptr
            hashTable[ptr]=1
            ptr=ptr.next
        return None

sol=Solution()
head=ListNode(3)
head.next=ListNode(2)
temp=head.next
head.next.next=ListNode(0)
head.next.next.next=ListNode(-4)
head.next.next.next.next=temp
result=sol.detectCycle(head)
print(result.val if result!=None else "Result is None.")