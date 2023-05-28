import java.util.ArrayList;

/**
 * Author:Jack Yang
 * Date:2023/05/28
 * Description:Intersection of Two Linked Lists
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ArrayList<ListNode> lta = new ArrayList<>();
        ArrayList<ListNode> ltb = new ArrayList<>();
        while (headA!=null){
            lta.add(headA);
            headA=headA.next;
        }
        while (headB!=null){
            ltb.add(headB);
            headB=headB.next;
        }
        for(ListNode n : lta){
            if(ltb.contains(n)){
                return n;
            }
        }
        return null;
    }
}
