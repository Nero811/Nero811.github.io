/**
 * Author:Jack Yang
 * Date:2023/07/31
 * Description:
 */
public class ListNode {
    protected int val;
    protected ListNode next;
    public ListNode() {}
    public ListNode(int val) {
        this.val = val;
        this.next = null;
    }
    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
