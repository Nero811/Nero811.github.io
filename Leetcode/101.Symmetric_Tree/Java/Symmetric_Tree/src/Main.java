/**
 * Author:Jack Yang
 * Date:2023/07/31
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        // TreeNode root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),new TreeNode(2, new TreeNode(4), new TreeNode(3)));
        TreeNode root = new TreeNode(1, new TreeNode(2), new TreeNode(2));
        root.left.right = new TreeNode(3);
        root.right.right = new TreeNode(3);
        Solution sol = new Solution();
        if (sol.isSymmetric(root)) {
            System.out.println("true");
        }
        else {
            System.out.println("false");
        }
    }
}
