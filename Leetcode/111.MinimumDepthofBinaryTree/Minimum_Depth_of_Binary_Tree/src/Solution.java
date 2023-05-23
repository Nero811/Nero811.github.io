import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Solution {
    public int minDepth(TreeNode root) {
        if(root==null)return 0;
        Queue<TreeNode>que=new LinkedList<TreeNode>();
        que.offer(root);
        int result=0;
        while(!que.isEmpty()){
            int size=que.size();
            result++;
            for(int i=0;i<size;i++){
                TreeNode node=que.poll();
                if(node.left!=null)que.offer(node.left);
                if(node.right!=null)que.offer(node.right);
                if(node.left==null && node.right==null)return result;
            }
        }
        return result;
    }
}
