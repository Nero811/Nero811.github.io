/**
 * Author:Jack Yang
 * Date:2023/06/12
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        /*TreeNode root = new TreeNode(5,new TreeNode(1),new TreeNode(4));
        root.right.left = new TreeNode(3);
        root.right.right = new TreeNode(6);*/

        /*TreeNode root = new TreeNode(5,new TreeNode(4),new TreeNode(6));
        root.right.left = new TreeNode(3);
        root.right.right = new TreeNode(7);*/

        TreeNode root = new TreeNode(3,new TreeNode(1),new TreeNode(5));
        root.left.left = new TreeNode(0);
        root.left.right = new TreeNode(2);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(6);

        Solution sol = new Solution();
        if (sol.isValidBST(root)){
            System.out.println("True");
        }
        else {
            System.out.println("False");
        }
    }
}
