/**
 * Author:Jack Yang
 * Date:2023/06/11
 * Description:Search in a Binary Search Tree
 */
public class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if (root.left == null && root.right == null)return root;
        while(root != null){
            if (val > root.val){
                root = root.right;
            }
            else if (val < root.val){
                root = root.left;
            }
            else if (val == root.val){
                return root;
            }
        }
        return null;
    }
}
