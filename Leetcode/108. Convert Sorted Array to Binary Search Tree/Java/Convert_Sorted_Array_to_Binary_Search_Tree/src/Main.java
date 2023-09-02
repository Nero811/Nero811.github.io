import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/09/02
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        int[] nums = {-10,-3,0,5,9};
        Solution sol = new Solution();
        TreeNode reuslt = sol.sortedArrayToBST(nums);
        Queue<TreeNode> que = new LinkedList<>();
        que.add(reuslt);
        while (! que.isEmpty()) {
            int size = que.size();
            for (int i = 0 ; i < size ; i++){
                TreeNode node = que.poll();
                System.out.println(node.val);
                if (node.left != null) {
                    que.add(node.left);
                }
                if (node.right != null) {
                    que.add((node.right));
                }
            }
        }
    }
}
