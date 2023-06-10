import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/06/10
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root1 = new TreeNode(1,new TreeNode(3),new TreeNode(2));
        root1.left.left = new TreeNode(5);
        TreeNode root2 = new TreeNode(2,new TreeNode(1),new TreeNode(3));
        root2.left.right = new TreeNode(4);
        root2.right.right = new TreeNode(7);
        Solution sol = new Solution();
        TreeNode result = sol.mergeTrees(root1,root2);
        Queue<TreeNode>que = new LinkedList<>();
        que.offer(result);
        while (!que.isEmpty()){
            int size = que.size();
            for (int i = 0 ; i < size ; i++){
                TreeNode node = que.poll();
                System.out.println(node.val);
                if (node.left != null) que.offer(node.left);
                if (node.right != null) que.offer(node.right);
            }
        }
    }
}
