from typing import Optional

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def getLength(self, head) -> int:
        len = 0
        cur = head
        while cur:
            len += 1
            cur = cur.next       
        return len

    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # 得到整個List的長度
        len = self.getLength(head)
        # 如果長度是0 表示沒有結點， 常度是1 表示怎麼翻轉都是頭節點， k == 0 表示不用翻轉，都返回head節點
        if len == 0 or len == 1 or k == 0:
            return head

        # 如果 k > len ，計算總共翻轉了幾次，餘數是翻轉後由尾向前算的第k的節點
        if k > len:
            k = k % len

        # index為計算長度-k，表示停在哪個節點上，為新的尾節點
        index = len - k
        cur = head
        # 如果index == 0 表示新的尾節點跟舊的尾節點相同， k == 0表示由尾往前數第0個節點，也是舊的尾節點，所以返回head
        if index == 0 or k == 0:
            return head
        else :
            # 找到新的尾節點
            while index > 1:
                index -= 1
                cur = cur.next
            # 宣告新的頭節點，為新的尾節點的next節點
            newHead = cur.next
            newCur = newHead
            # 遍歷新的頭節點直到尾端
            while newCur.next:
                newCur = newCur.next
            # 將新的尾節點的next定為None
            cur.next = None
            # 新的頭節點連到舊的頭節點
            newCur.next = head

        return newHead

if __name__ == "__main__":
    sol = Solution()
    #head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    head = ListNode(0, ListNode(1, ListNode(2)))
    k = 4
    result = sol.rotateRight(head, k)
    while result:
        print(result.val)
        result = result.next