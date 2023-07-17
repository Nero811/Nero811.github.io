import java.util.ArrayList;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/17
 * Description:
 */

public class Solution {
    public ListNode detectCycle(ListNode head) {
        List<ListNode> lt = new ArrayList<>();
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode ptr = dummyHead.next;
        while (ptr != null) {
            if (!lt.isEmpty() && lt.contains(ptr)) {
                return ptr;
            }
            lt.add(ptr);
            ptr = ptr.next;
        }
        return null;
    }
}
