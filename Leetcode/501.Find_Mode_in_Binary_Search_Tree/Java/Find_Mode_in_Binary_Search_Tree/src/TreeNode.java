/**
 * Author:Jack Yang
 * Date:2023/06/14
 * Description:
 */
public class TreeNode {
    protected int val;
    protected TreeNode left;
    protected TreeNode right;
    protected TreeNode(){}
    protected TreeNode(int val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
    protected TreeNode(int val, TreeNode left, TreeNode right){
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
