from typing import Optional

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None and list2 == None:
            return None
        
        dummyHead = ListNode(-1)
        ptr = dummyHead
        dic = {}
        while list1 != None or list2 != None:
            if list1 != None:
                dic[list1] = list1.val
            if list2 != None:
                dic[list2] = list2.val
            if list1 != None:
                list1 = list1.next
            if list2 != None:
                list2 = list2.next
        sortedDic = dict(sorted(dic.items(), key=lambda item: item[1]))
        for key in sortedDic.keys():
            ptr.next = key
            ptr = ptr.next
        return dummyHead.next

#list1 = ListNode(1, ListNode(2, ListNode(4)))
#list2 = ListNode(1, ListNode(3, ListNode(4)))
list1 = ListNode(2)
list2 = ListNode(1)
sol = Solution()
result = sol.mergeTwoLists(list1, list2)
while result != None:
    print(result.val)
    result = result.next




        