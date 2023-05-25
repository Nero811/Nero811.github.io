public class Solution extends ListNode{
    public ListNode removeElements(ListNode head, int val) {
        if(head!=null && head==null)return null;
        while (head.val==val){
            head=head.next;
        }
        ListNode dummyhead=null;
        ListNode pre=head;
        if(pre!=null)dummyhead = pre.next;
        while(pre!=null){
            while (dummyhead!=null && dummyhead.val==val){
                pre.next=dummyhead.next;
                dummyhead=dummyhead.next;
            }
            pre=pre.next;
            if(pre!=null)dummyhead=pre.next;
        }
        return head;
    }
}
