import javax.swing.tree.TreeNode;

/**
 * Author:Jack Yang
 * Date:2023/05/26
 * Description:Solution Class
 */
public class Solution {
    protected ListNode dummy;
    protected ListNode cur;
    public ListNode SwapNode(ListNode node1, ListNode node2){
        ListNode temp;
        temp=node2.next;
        node2.next=node1;
        node1.next=temp;
        this.cur=node1;
        this.dummy=node2;
        return node2;
    }
    public ListNode swapPairs(ListNode head) {
        if(head==null)return null;
        else if(head.next==null)return head;
        ListNode head2=head.next;
        this.dummy=new ListNode(-1);
        dummy.next=head;
        ListNode pre=dummy;
        this.cur=head;
        int cnt=1;
        while(this.cur!=null){
            if(cnt==2){
                pre.next=this.SwapNode(this.dummy,this.cur);
                pre=this.cur;
                System.out.println("pre.val: "+ pre.val);
                this.cur=this.cur.next;
                cnt=1;
            }
            this.dummy=this.cur;
            if(this.cur!=null)this.cur=this.cur.next;
            cnt++;
        }
        return head2;
    }
}
