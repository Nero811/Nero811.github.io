import java.util.LinkedList;
import java.util.List;

public class Solution {
    private static List<Integer> result = new LinkedList<>();

    /*
     * 史用遞迴中序遍歷
     */
    public static List<Integer> inorderTraversal(TreeNode root) {
        if (root == null) {
            return result;
        }
        inorderTraversal(root.left);
        result.add(root.val);
        inorderTraversal(root.right);
        return result;
    }

    public static void main(String[] args) throws Exception {
        TreeNode root = new TreeNode(1, null, new TreeNode(2, new TreeNode(3), null));
        inorderTraversal(root);
        result.forEach(num -> {
            System.out.print(num + " ");
        });
    }
}
