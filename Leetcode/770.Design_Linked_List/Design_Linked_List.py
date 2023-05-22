# -*- coding: utf-8 -*-
"""
Created on Mon Apr 10 21:33:40 2023

@author: User
"""

class Node:
    def __init__(self,val:int):
        self.data=val
        self.next=None
class MyLinkedList:
    def __init__(self):
        self.head=None

    def get(self, index: int) -> int:
        cnt=0
        ptr = self.head
        while ptr.next!=None:
            if index==0:
                return ptr.data
            if ptr.next!=None:
                ptr=ptr.next
                cnt+=1
            if cnt == index:
                return ptr.data    
        return -1
        
    def addAtHead(self, val: int) -> None:
        if self.head==None:
            self.head=Node(val)
        elif self.head!=None:
            tmp = Node(val)
            tmp.next=self.head
        

    def addAtTail(self, val: int) -> None:
        if self.head==None:
            self.head=Node(val)
        else:
            ptr=self.head
            while ptr.next!=None:
                ptr=ptr.next
            tmp = Node(val)
            ptr.next=tmp

    def addAtIndex(self, index: int, val: int) -> None:
        cnt=0
        ptr = self.head
        while ptr.next!=None:
            pre=ptr
            if ptr.next!=None:
                ptr=ptr.next    
                cnt+=1    
            if cnt == index:
                if ptr.next!=None:
                    ptr=ptr.next
                    newNode=Node(val)
                    pre.next=newNode
                    newNode.next=ptr
                elif ptr.next==None:
                    newNode=Node(val)
                    pre.next=newNode
                    newNode.next=ptr
            elif ptr.next==None and index > cnt:
                newNode=Node(val)
                ptr.next=newNode    

    def deleteAtIndex(self, index: int) -> None:
         cnt=0
         ptr = self.head
         while ptr.next!=None:
             pre=ptr
             if index == 0:
                 if self.head.next!=None:
                     self.head=self.head.next
                 else:
                     self.head=None
                 return
             if ptr.next!=None:
                 ptr=ptr.next
                 cnt+=1
             if cnt == index:
                 if ptr.next!=None:
                    ptr=ptr.next
                    pre.next=ptr   
                 else:
                    pre.next=None
                 return
             

myLink=MyLinkedList()
myLink.addAtHead(1)
myLink.addAtTail(3)
myLink.addAtIndex(1, 2)
print(myLink.get(1))
myLink.deleteAtIndex(1)
print(myLink.get(1))
# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)