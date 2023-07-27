import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/07/27
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        TreeNode root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
        TreeNode result = sol.invertTree(root);
        Queue<TreeNode> que = new LinkedList<>();
        que.add(result);
        while (!que.isEmpty()) {
            int size = que.size();
            for (int i = 0 ; i < size ; i++) {
                TreeNode node = que.peek();
                que.poll();
                System.out.println(node.val);
                if (node.left != null) {
                    que.add(node.left);
                }
                if (node.right != null) {
                    que.add(node.right);
                }
            }
        }
    }
}
