import javax.swing.tree.TreeNode;

/**
 * Author:Jack Yang
 * Date:
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        ListNode head = new ListNode(3);
        head.next = new ListNode(2);
        head.next.next = new ListNode(0);
        head.next.next.next = new ListNode(-4);
        head.next.next.next.next = head.next;
        Solution sol = new Solution();
        System.out.println(sol.detectCycle(head).val);
    }
}
