public class Main extends ListNode{
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(6);
        head.next.next.next = new ListNode(3);
        head.next.next.next.next = new ListNode(4);
        head.next.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next.next = new ListNode(6);
        Solution sol = new Solution();
        int val=6;
        head = sol.removeElements(head,val);
        while(head != null){
            System.out.println(head.val + " ");
            head=head.next;
        }
    }
}
