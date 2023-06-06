import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/06/06
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        int[] inorder = {9,3,15,20,7};
        int[] preorder =  {3,9,20,15,7};
       // int[] inorder = {3,2,1};
       // int[] preorder = {1,2,3};
        Solution sol = new Solution();
        TreeNode result = sol.buildTree(preorder,inorder);
        Queue<TreeNode> que = new LinkedList<>();
        que.offer(result);
        while (!que.isEmpty()){
            int size = que.size();
            for(int i=0; i < size ; i++){
                TreeNode node = que.poll();
                System.out.println(node.val);
                if(node.left!=null)que.offer(node.left);
                if(node.right!=null)que.offer(node.right);
            }
        }
    }
}
