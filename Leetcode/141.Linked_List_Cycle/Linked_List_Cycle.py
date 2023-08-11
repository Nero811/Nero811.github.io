from typing import Optional

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        dic = {}
        while head != None:
            if dic.get(head):
                return True
            else:
                dic[head] = 1

            head = head.next
        
        return False
    
sol = Solution()
head = ListNode(3)
head.next = ListNode(2)
head.next.next = ListNode(0)
head.next.next.next = ListNode(-4, head.next)

if sol.hasCycle(head):
    print("True")
else:
    print("False")


        