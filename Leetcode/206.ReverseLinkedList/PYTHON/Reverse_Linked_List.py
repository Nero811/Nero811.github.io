# -*- coding: utf-8 -*-
"""
Created on Sat Apr 15 14:41:23 2023

@author: User
"""
from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
class Solution:
    def recursive(self,cur :Optional[ListNode],ptr :Optional[ListNode])->Optional[ListNode]:
        if ptr==None:
            return cur
        temp=ptr.next
        pre=ptr
        pre.next=cur
        return self.recursive(pre,temp)
        
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur=None
        result=self.recursive(cur,head)
        return result
    
sol=Solution()
head=ListNode(1)
ptr=head
ptr.next=ListNode(2)
ptr.next.next=ListNode(3)
ptr.next.next.next=ListNode(4)
ptr.next.next.next.next=ListNode(5)
result=sol.reverseList(ptr)
while result!=None:
    print(result.val)
    result=result.next