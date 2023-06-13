/**
 * Author:Jack Yang
 * Date:2023/06/13
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(4,new TreeNode(2),new TreeNode(6));
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);

        /*TreeNode root = new TreeNode(1);
        root.right = new TreeNode(3);
        root.right.left = new TreeNode(2);*/
        Solution sol = new Solution();
        System.out.println(sol.getMinimumDifference(root));
    }
}
