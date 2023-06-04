/**
 * Author:Jack Yang
 * Date:2023/06/04
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(5, new TreeNode(4), new TreeNode(8));
        root.left.left = new TreeNode(11, new TreeNode(7), new TreeNode(2));
        root.right.left = new TreeNode(13);
        root.right.right = new TreeNode(4);
        Solution sol = new Solution();
        int targetSum = 22;
        if (sol.hasPathSum(root,targetSum)){
            System.out.println("True");
        }
        else {
            System.out.println("False");
        }
    }
}
