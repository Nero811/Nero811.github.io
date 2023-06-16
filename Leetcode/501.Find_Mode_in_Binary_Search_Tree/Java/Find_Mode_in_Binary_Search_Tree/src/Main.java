/**
 * Author:Jack Yang
 * Date:2023/06/14
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.left = new TreeNode(2);
        /*TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);*/
        Solution sol = new Solution();
        for (Integer i : sol.findMode(root)){
            System.out.println(i);
        }
    }
}
