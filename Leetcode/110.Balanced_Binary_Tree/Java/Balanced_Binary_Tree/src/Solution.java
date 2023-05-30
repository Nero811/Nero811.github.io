import java.util.Stack;

/**
 * Author:Jack Yang
 * Date:2023/05/30
 * Description:Solution Class
 */
public class Solution {
    public int travel(TreeNode root){
        if(root==null){
            return 0;
        }
        int leftDepth=travel(root.left);
        if(leftDepth == -1)return -1;
        int rightDepth=travel(root.right);
        if(rightDepth == -1)return -1;
        int result;
        if(Math.abs(leftDepth - rightDepth)>1){
            result = -1;
        }
        else {
            result = 1 + Math.max(leftDepth,rightDepth);
        }
        return result;
    }
    public boolean isBalanced(TreeNode root) {
        if(root==null)return true;
        int result=this.travel(root);
        if(result==-1)return false;
        else return true;
    }
}
