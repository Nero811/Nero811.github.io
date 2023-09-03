/**
 * Author:Jack Yang
 * Date:2023/09/03
 * Description:
 */
public class TreeNode {
    protected int val;
    protected TreeNode left;
    protected TreeNode right;
    TreeNode(){}
    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
