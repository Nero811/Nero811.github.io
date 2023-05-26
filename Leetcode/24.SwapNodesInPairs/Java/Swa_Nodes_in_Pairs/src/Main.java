/**
 * Author:Jack Yang
 * Date:2023/05/26
 * Description:Main Class
 */
public class Main extends Solution{
    public static void main(String[] args) {
        ListNode head=new ListNode(1);
        head.next=new ListNode(2);
        head.next.next=new ListNode(3);
        head.next.next.next=new ListNode(4);
        Solution sol = new Solution();
        ListNode result=sol.swapPairs(head);
        while (result!=null){
            System.out.println(result.val);
            result=result.next;
        }
    }
}
