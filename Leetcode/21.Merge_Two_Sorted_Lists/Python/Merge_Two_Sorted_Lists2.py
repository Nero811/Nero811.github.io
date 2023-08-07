from typing import Optional

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode(-1)
        cur = dummyHead
        while list1 and list2:
            if list1.val <= list2.val:
                cur.next = list1
                list1 = list1.next
            else:
                cur.next = list2
                list2 = list2.next
            cur = cur.next
        
        if list1 == None and list2:
            cur.next = list2
        elif list2 == None and list1:
            cur.next = list1
        return dummyHead.next

list1 = ListNode(1, ListNode(2, ListNode(4)))
list2 = ListNode(1, ListNode(3, ListNode(4)))
#list1 = ListNode(2)
#list2 = ListNode(1)
sol = Solution()
result = sol.mergeTwoLists(list1, list2)
while result != None:
    print(result.val)
    result = result.next




        