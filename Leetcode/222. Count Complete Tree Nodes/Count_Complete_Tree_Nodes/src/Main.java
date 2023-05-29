/**
 * Author:Jack Yang
 * Date:2023/05/29
 * Description:Count Complete Tree Nodes
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2,new TreeNode(4),new TreeNode(5));
        root.right = new TreeNode(3,new TreeNode(6),null);
        Solution sol = new Solution();
        System.out.println(sol.countNodes(root));
    }
}
