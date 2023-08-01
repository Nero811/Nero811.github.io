from typing import Optional

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        st1 = []
        st2 = []
        first = True
        while l1 != None:
            st1.append(l1)
            l1 = l1.next

        while l2 != None:
            st2.append(l2)
            l2 = l2.next

        dummyHead = ListNode(-1)
        head = dummyHead

        st1Val = 0
        cnt = (10 ** (len(st1) - 1))
        while len(st1) > 0:
            n1 = st1.pop()
            st1Val += (n1.val * cnt)
            cnt //= 10

        st2Val = 0
        cnt = (10 ** (len(st2) - 1))
        while len(st2) > 0:
            n2 = st2.pop()
            st2Val += (n2.val * cnt)
            cnt //= 10
        
        st3Val = st1Val + st2Val

        if st3Val == 0:
            head = ListNode(0)
            return head
        
        dummyHead = ListNode(-1)
        head = dummyHead
        while st3Val > 0:
            dummyHead.next = ListNode(st3Val % 10)
            dummyHead = dummyHead.next
            st3Val //= 10
            if first:
                head = dummyHead
                first = False

        return head

# l1 = ListNode(2)
# l1.next = ListNode(4)
# l1.next.next = ListNode(3)

l1 = ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9)))))))
l2 = ListNode(9, ListNode(9, ListNode(9, ListNode(9))))

# l1 = ListNode(2, ListNode(4, ListNode(9)))
# l2 = ListNode(5, ListNode(6, ListNode(4 ,ListNode(9))))

sol = Solution()
result = sol.addTwoNumbers(l1, l2)
while result != None:
    print(result.val)
    result = result.next


                

