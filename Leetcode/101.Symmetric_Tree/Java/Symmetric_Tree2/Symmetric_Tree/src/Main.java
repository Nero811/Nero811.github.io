/**
 * Author:Jack Yang
 * Date:2023/09/06
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        //TreeNode root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
        TreeNode root = new TreeNode(1, new TreeNode(2), new TreeNode(2));
        root.left.right = new TreeNode(3);
        root.right.right = new TreeNode(3);
        Solution sol = new Solution();
        System.out.println(sol.isSymmetric(root));
    }
}
