/**
 * Author:Jack Yang
 * Date:2023/06/20
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3,new TreeNode(5,new TreeNode(6),new TreeNode(2,new TreeNode(7),new TreeNode(4))),new TreeNode(1,new TreeNode(0),new TreeNode(8)));
        Solution sol = new Solution();
        /*TreeNode p = root.left;
        TreeNode q = root.left.right.right;*/
        /*TreeNode p = root.left;
        TreeNode q = root.right;*/
        /*TreeNode p = root.right.left;
        TreeNode q = root.right.right;*/
        TreeNode p = root.left.right;
        TreeNode q = root.right;
        System.out.println(sol.lowestCommonAncestor(root,p,q).val);
    }
}
