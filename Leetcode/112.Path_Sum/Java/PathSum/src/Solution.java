/**
 * Author:Jack Yang
 * Date:2023/06/04
 * Description:Leetcode 112 Path Sum Solution
 */
public class Solution {
    private boolean left;
    private boolean right;
    private boolean result;
    public boolean travel(TreeNode root, int targetSum ,int sum){
        sum += root.val;
        if(root.left == null && root.right == null){
            if(targetSum == sum){
                return true;
            }
            else{
                return false;
            }
        }
        if (root.left != null){
            left = travel(root.left, targetSum, sum);
        }
        if (left){
            result = true;
            return result;
        }
        if (root.right != null){
            right = travel(root.right, targetSum, sum);
        }
        if (right){
            result = true;
            return result;
        }
        return result;
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null)return false;
        left = false;
        right = false;
        result = false;
        return this.travel(root, targetSum , 0);
    }
}
