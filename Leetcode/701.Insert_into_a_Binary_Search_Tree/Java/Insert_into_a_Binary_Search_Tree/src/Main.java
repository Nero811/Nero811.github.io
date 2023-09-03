import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/09/03
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        //TreeNode root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));
        TreeNode root = new TreeNode(40, new TreeNode(20, new TreeNode(10), new TreeNode(30)), new TreeNode(60, new TreeNode(50), new TreeNode(70)));
        Solution sol = new Solution();
        int val = 25;
        TreeNode result = sol.insertIntoBST(root, val);
        Queue<TreeNode> que = new LinkedList<>();
        que.add(result);
        while (! que.isEmpty()) {
            int size = que.size();
            for (int i = 0; i < size ; i++) {
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
