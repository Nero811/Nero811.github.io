from typing import Optional

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        st1 = ""
        st2 = ""
        while head:
            st1 += str(head.val)
            st2 = str(head.val) + st2
            head = head.next
        
        if st1 != st2:
            return False
        return True

sol = Solution()
head = ListNode(1, ListNode(2, ListNode(2, ListNode(1))))
if sol.isPalindrome(head):
    print("True")
else:
    print("False")
            