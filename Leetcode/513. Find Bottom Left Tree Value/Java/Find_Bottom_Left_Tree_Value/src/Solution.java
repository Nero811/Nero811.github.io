import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/06/02
 * Description:Solution
 */
public class Solution {
    public int findBottomLeftValue(TreeNode root) {
        if(root.left==null && root.right==null)return root.val;
        Queue<TreeNode> que = new LinkedList<>();
        que.offer(root);
        int result = root.val;
        while(!que.isEmpty()){
            int size = que.size();
            for(int i=0 ; i < size ;i++){
                TreeNode node = que.poll();
                if(node.left != null)que.offer(node.left);
                if(node.right != null)que.offer(node.right);
            }
            if(!que.isEmpty())result = que.peek().val;
        }
        return result;
    }
}
