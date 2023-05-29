import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/05/29
 * Description:Count Complete Tree Nodes
 */
public class Solution {
    public int countNodes(TreeNode root) {
        if(root==null)return 0;
        Queue<TreeNode> que = new LinkedList<>();
        que.offer(root);
        int result=0;
        while(!que.isEmpty()){
            int size = que.size();
            for(int i=0 ; i < size ; i++){
                TreeNode node = que.poll();
                result++;
                if(node.left!=null)que.offer(node.left);
                if(node.right!=null)que.offer(node.right);
            }
        }
        return result;
    }
}
