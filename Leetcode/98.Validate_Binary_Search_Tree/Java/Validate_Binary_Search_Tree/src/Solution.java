/**
 * Author:Jack Yang
 * Date:2023/06/12
 * Description:Validate Binary Search Tree
 */
public class Solution {
    private long pre = Long.MIN_VALUE;
    public boolean isValidBST(TreeNode root) {
        if(root == null){
            return true;
        }
        boolean left = isValidBST(root.left);
        if (!left) return false;
        if (root.val <= pre) return false;
        pre = root.val;
        boolean right = isValidBST(root.right);
        if (!right) return false;
        return true;
    }
}
