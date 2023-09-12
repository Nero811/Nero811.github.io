import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/09/12
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6));
        root.right.right = new TreeNode(7);
        Solution sol = new Solution();
        int key = 3;
        TreeNode result = sol.deleteNode(root, 3);
        Queue<TreeNode> que = new LinkedList<>();
        que.add(result);
        while (!que.isEmpty()) {
            int size = que.size();
            for (int i = 0 ; i < size ; i++) {
                TreeNode node = que.poll();
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
