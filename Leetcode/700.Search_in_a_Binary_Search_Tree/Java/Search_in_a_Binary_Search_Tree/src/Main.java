import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/06/11
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(4,new TreeNode(2),new TreeNode(7));
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        Solution sol = new Solution();
        int val = 2;
        TreeNode result = sol.searchBST(root,val);
        Queue<TreeNode> que = new LinkedList<>();
        if (result != null){
            que.offer(result);
        }
        else {
            System.out.println("result is null");
        }
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
