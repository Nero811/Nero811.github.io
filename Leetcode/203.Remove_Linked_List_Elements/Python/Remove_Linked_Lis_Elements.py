# -*- coding: utf-8 -*-
"""
Created on Sun Apr  9 11:10:10 2023

@author: User
"""
from typing import Optional
class ListNode:
    def __init__(self, val=0,next=None):
         self.val = val
         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        root=head
        if head==None:
            return None
        while root.val==val:
               root=root.next
               if root==None:
                   break
        if root==None:
            return None
        ptr=root
        pre=ptr
        while ptr!=None:
            pre=ptr
            ptr=ptr.next
            while ptr!=None and ptr.val==val:
                ptr=ptr.next
                pre.next=ptr
        return root
    
root=ListNode(1)
ptr=root
'''ptr.next=ListNode(2)
ptr=ptr.next
ptr.next=ListNode(6)
ptr=ptr.next
ptr.next=ListNode(3)
ptr=ptr.next
ptr.next=ListNode(4)
ptr=ptr.next
ptr.next=ListNode(5)
ptr=ptr.next
ptr.next=ListNode(6)
ptr=ptr.next'''
ptr.next=ListNode(2)
ptr=ptr.next
ptr.next=ListNode(2)
ptr=ptr.next
ptr.next=ListNode(1)
ptr=ptr.next

sol=Solution()
val=2
result=sol.removeElements(root, val)
ptr=result
while ptr!=None:
    print(ptr.val)
    ptr=ptr.next
