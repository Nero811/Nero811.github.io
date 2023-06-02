/**
 * Author:Jack Yang
 * Date:2023/06/02
 * Description:Main
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1,new TreeNode(2),new TreeNode(3));
        root.left.left = new TreeNode(4);
        root.right.left = new TreeNode(5);
        root.right.right = new TreeNode(6);
        root.right.left.left = new TreeNode(7);
        Solution sol = new Solution();
        System.out.println(sol.findBottomLeftValue(root));
    }
}
