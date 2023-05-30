/**
 * Author:Jack Yang
 * Date:2023/05/30
 * Description:Main Class
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1,new TreeNode(2),new TreeNode(2));
        root.left.left=new TreeNode(3);
        root.left.right=new TreeNode(3);
        root.left.left.left= new TreeNode(4);
        root.left.left.right=new TreeNode(4);
        Solution sol = new Solution();
        if(sol.isBalanced(root))System.out.println("True");
        else System.out.println("False");
    }
}
