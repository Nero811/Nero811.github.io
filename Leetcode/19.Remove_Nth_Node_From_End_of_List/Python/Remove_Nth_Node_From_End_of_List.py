from typing import Optional

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        size = 0
        dummyHead = ListNode(-1)
        dummyHead.next = head
        slowHead = dummyHead.next
        firstHead = dummyHead.next
        # 先統計出總共有幾的結點
        while firstHead:
            size += 1
            firstHead = firstHead.next
        # 定義target 為結點的數量的計數器，初始值為一
        target = 1
        while target <= (size - n):
            # 當 target == size - n 時，刪除結點
            if target == (size - n):
                slowHead.next = slowHead.next.next
                return dummyHead.next
            slowHead = slowHead.next
            target += 1
        # 表示size - n == 0，直接刪除第一個結點
        return dummyHead.next.next

if __name__ == "__main__":
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    n = 2
    sol = Solution()
    result = sol.removeNthFromEnd(head, n)
    while result:
        print(result.val)
        result = result.next

            
        
