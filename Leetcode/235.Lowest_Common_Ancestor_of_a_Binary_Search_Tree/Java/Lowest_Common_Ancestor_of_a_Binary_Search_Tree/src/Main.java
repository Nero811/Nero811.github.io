/**
 * Author:Jack Yang
 * Date:2023/06/21
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(6,new TreeNode(2,new TreeNode(0),new TreeNode(4,new TreeNode(3),new TreeNode(5))),new TreeNode(8,new TreeNode(7),new TreeNode(9)));
        Solution sol = new Solution();
        TreeNode p = root.left.right.left;
        TreeNode q = root.left.right.right;
        System.out.println(sol.lowestCommonAncestor(root,p,q).val);
    }
}
