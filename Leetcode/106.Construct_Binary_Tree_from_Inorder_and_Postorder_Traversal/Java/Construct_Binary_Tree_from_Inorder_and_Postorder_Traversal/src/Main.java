import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/06/05
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        int[] inorder = {9,3,15,20,7};
        int[] postorder = {9,15,7,20,3};
        Solution sol = new Solution();
        TreeNode root = sol.buildTree(inorder,postorder);
        Queue<TreeNode> que = new LinkedList<>();
        que.offer(root);
        while (!que.isEmpty()){
            int size = que.size();
            for (int i = 0 ; i < size ; i++){
                TreeNode node = que.poll();
                System.out.println(node.val);
                if(node.left != null)que.offer(node.left);
                if(node.right != null)que.offer(node.right);
            }
        }
    }
}
