import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/06/09
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        int[] nums = {3,2,1,6,0,5};
        Solution sol = new Solution();
        TreeNode root = sol.constructMaximumBinaryTree(nums);
        Queue<TreeNode> que = new LinkedList<>();
        que.offer(root);
        while (!que.isEmpty()){
            int size = que.size();
            for (int i = 0 ; i < size ; i++){
                TreeNode node = que.poll();
                System.out.println(node.val);
                if (node.left!=null)que.offer(node.left);
                if (node.right!=null)que.offer(node.right);
            }
        }
    }
}
