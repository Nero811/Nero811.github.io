/**
 * Author:Jack Yang
 * Date:2023/05/27
 * Description:Main Class
 */
public class Main {
    public static void main(String[] args) {
        ListNode head=new ListNode(1);
        head.next=new ListNode(2);
        head.next.next=new ListNode(3);
        head.next.next.next=new ListNode(4);
        head.next.next.next.next=new ListNode(5);
        Solution sol = new Solution();
        int n = 2;
        ListNode result = sol.removeNthFromEnd(head,2);
        while(result!=null){
            System.out.println(result.val);
            result=result.next;
        }
    }
}
