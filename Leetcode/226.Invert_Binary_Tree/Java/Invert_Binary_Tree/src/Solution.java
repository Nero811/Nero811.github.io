import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/07/27
 * Description:226. Invert Binary Tree
 */
public class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return root;
        }
        Queue<TreeNode> que = new LinkedList<>();
        que.add(root);

        while (!que.isEmpty()) {
            int size = que.size();
            for (int i = 0 ; i < size ; i++) {
                TreeNode node = que.peek();
                que.poll();
                if (node.left != null) {
                    que.add(node.left);
                }
                if (node.right != null) {
                    que.add(node.right);
                }
                TreeNode tmp = node.left;
                node.left = node.right;
                node.right = tmp;
            }
        }

        return root;
    }
}
