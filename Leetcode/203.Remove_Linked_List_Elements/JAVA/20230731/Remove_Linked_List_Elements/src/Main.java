/**
 * Author:Jack Yang
 * Date:2023/07/31
 * Description:
 */
public class Main {
    public static void main(String[] args) {
//        ListNode head = new ListNode(1);
//        head.next = new ListNode(2);
//        head.next.next = new ListNode(6);
//        head.next.next.next = new ListNode(3);
//        head.next.next.next.next = new ListNode(4);
//        head.next.next.next.next.next = new ListNode(5);
//        head.next.next.next.next.next.next = new ListNode(6);
        ListNode head = new ListNode(7);
        head.next = new ListNode(7);
        head.next.next = new ListNode(7);
        head.next.next.next = new ListNode(7);

        int target = 7;
        Solution sol = new Solution();
        ListNode result = sol.removeElements(head, target);
        while (result != null) {
            System.out.println(result.val);
            result = result.next;
        }
    }
}
