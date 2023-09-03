/**
 * Author:Jack Yang
 * Date:2023/09/03
 * Description:
 */
public class Solution {
    public TreeNode travel(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        if (root.val > val) {
            root.left = travel(root.left, val);
        }
        if (root.val < val) {
            root.right = travel(root.right, val);
        }
        return root;
    }
    public TreeNode insertIntoBST(TreeNode root, int val) {
        return travel(root, val);
    }
}
