/**
 * Author:Jack Yang
 * Date:2023/07/31
 * Description:203. Remove Linked List Elements
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode pre = dummyHead;
        while (head != null) {
            while (head != null && head.val == val) {
                head = head.next;
                pre.next = head;
            }
            pre = pre.next;
            if (head != null) {
                head = head.next;
            }
            if (pre != null) {
                pre.next = head;
            }
        }
        return dummyHead.next;
    }
}
