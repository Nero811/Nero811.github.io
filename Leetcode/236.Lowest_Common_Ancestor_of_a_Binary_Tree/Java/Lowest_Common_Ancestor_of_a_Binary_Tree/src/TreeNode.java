/**
 * Author:Jack Yang
 * Date:2023/06/20
 * Description:
 */
public class TreeNode {
    protected int val;
    protected TreeNode left;
    protected TreeNode right;
    public TreeNode(){}
    public TreeNode(int val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
    public TreeNode(int val, TreeNode left, TreeNode right){
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
