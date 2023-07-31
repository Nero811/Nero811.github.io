import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/07/31
 * Description:101. Symmetric Tree
 */
public class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root.left == null && root.right == null) {
            return true;
        }
        Queue<TreeNode> queLeft = new LinkedList<>();
        Queue<TreeNode> queRight = new LinkedList<>();
        queLeft.add(root.left);
        queRight.add(root.right);
        while (!queLeft.isEmpty() || !queRight.isEmpty()) {
            int sizeLeft = queLeft.size();
            int sizeRight = queRight.size();
            if (sizeLeft != sizeRight) {
                return false;
            }
            for (int i = 0 ; i < sizeLeft ; i++) {
                TreeNode nodeLeft = queLeft.poll();
                TreeNode nodeRight = queRight.poll();
                if ((nodeLeft == null && nodeRight != null) || (nodeLeft != null && nodeRight == null) || (nodeLeft !=null && nodeRight != null && nodeLeft.val != nodeRight.val)) {
                    return false;
                }
                if (nodeLeft != null) {
                    queLeft.add(nodeLeft.left);
                    queLeft.add(nodeLeft.right);
                }
                if (nodeRight != null) {
                    queRight.add(nodeRight.right);
                    queRight.add(nodeRight.left);
                }
            }
        }
        return true;
    }
}
