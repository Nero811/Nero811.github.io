/**
 * Author:Jack Yang
 * Date:2023/06/01
 * Description:Main
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3,new TreeNode(9),new TreeNode(20));
        root.right.left=new TreeNode(15);
        root.right.right=new TreeNode(7);
        Solution sol = new Solution();
        System.out.println(sol.sumOfLeftLeaves(root));
    }
}
