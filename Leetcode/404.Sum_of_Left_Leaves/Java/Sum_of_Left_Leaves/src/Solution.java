/**
 * Author:Jack Yang
 * Date:2023/06/01
 * Description:
 */
public class Solution {
    private int result;
    public void travel(TreeNode root,TreeNode parent){
        if(root.left==null && root.right==null){
            if(parent.left==root){
                result+=root.val;
            }
            return;
        }
        if(root.left!=null)travel(root.left,root);
        if(root.right!=null)travel(root.right,root);
        return;
    }
    public int sumOfLeftLeaves(TreeNode root) {
        if(root.left==null && root.right==null)return 0;
        result=0;
        travel(root,null);
        return result;
    }
}
