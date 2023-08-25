from typing import Optional

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        lt = []
        dummyHead = ListNode(-1)
        dummyHead.next = head
        cur = dummyHead.next
        while cur:
            lt.append(cur)
            cur = cur.next
        
        j = len(lt) - 1
        i = 1
        while i < j:
            head.next = lt[j]
            head.next.next = lt[i]
            head = head.next.next
            j -= 1
            i += 1
        
        if len(lt) % 2 == 0:
            head.next = lt[i]
            head = head.next
        
        head.next = None

        return dummyHead.next

if __name__ == "__main__":
    #head = ListNode(1,ListNode(2,ListNode(3,ListNode(4,ListNode(5)))))
    head = ListNode(1,ListNode(2,ListNode(3,ListNode(4))))
    sol = Solution()
    result = sol.reorderList(head)
    while result:
        print(result.val)
        result = result.next
                               
