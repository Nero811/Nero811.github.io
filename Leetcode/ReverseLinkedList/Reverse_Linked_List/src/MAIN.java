import Solution.ListNode;
import Solution.Solution;

public class MAIN {
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next=new ListNode(2);
        head.next.next=new ListNode(3);
        head.next.next.next=new ListNode(4);
        head.next.next.next.next=new ListNode(5);
        Solution sol = new Solution();
        ListNode result = sol.reverseList(head);
        while(result!=null){
            System.out.println(result.val);
            result=result.next;
        }
    }
}
