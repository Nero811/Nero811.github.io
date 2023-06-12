/**
 * Author:Jack Yang
 * Date:2023/06/12
 * Description:
 */
public class TreeNode {
    protected int val;
    protected TreeNode left;
    protected TreeNode right;
    public TreeNode(){}
    public TreeNode(int val){
        this.val = val;
    }
    public TreeNode(int val,TreeNode left,TreeNode right){
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
