/**
 * Author:Jack Yang
 * Date:2023/05/28
 * Description:Intersection of Two Linked Lists
 */
public class Main {
    public static void main(String[] args) {
        ListNode listA = new ListNode(1);
        listA.next = new ListNode(9);
        listA.next.next = new ListNode(1);
        listA.next.next.next = new ListNode(2);
        listA.next.next.next.next = new ListNode(4);

        ListNode listB = new ListNode(3);
        listB.next = listA.next.next.next;
        listB.next.next = listA.next.next.next.next;

        Solution sol = new Solution();
        ListNode result = sol.getIntersectionNode(listA,listB);
        if(result!=null){
            System.out.println(result.val);
        }
        else{
            System.out.println("NULL");
        }
    }
}
