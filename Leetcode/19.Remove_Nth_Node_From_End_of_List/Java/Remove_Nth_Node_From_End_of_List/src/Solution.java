/**
 * Author:Jack Yang
 * Date:2023/05/27
 * Description:Solution Class
 */
public class Solution {
    public int GetListSize(ListNode head){
        int size=1;
        while(head!=null){
            head=head.next;
            size++;
        }
        return size;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null)return null;
        int listSize=this.GetListSize(head);
        ListNode dummy=new ListNode(-1);
        dummy.next=head;
        ListNode cur=head;
        ListNode pre=dummy;
        int cnt=1;
        while(cur!=null){
            if(cnt==(listSize-n)){
                pre.next=cur.next;
            }
            pre=pre.next;
            cur=cur.next;
            cnt++;
        }
        return dummy.next;
    }
}
