package Solution;

public class Solution {
    public ListNode reverseList(ListNode head) {
        if(head==null)return null;
        ListNode dummyhead = new ListNode();
        dummyhead = head;
        ListNode temp=dummyhead;
        ListNode ptr = null;
        while(temp!=null){
            temp = dummyhead.next;
            dummyhead.next=ptr;
            ptr=dummyhead;
            if(temp!=null)dummyhead=temp;
        }
        head=dummyhead;
        return head;
    }
}
