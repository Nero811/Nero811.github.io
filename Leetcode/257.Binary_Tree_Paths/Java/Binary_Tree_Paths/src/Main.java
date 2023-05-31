import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/05/31
 * Description:Main Class
 */
public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1,new TreeNode(2),new TreeNode(3));
        root.left.right = new TreeNode(5);
        Solution sol = new Solution();
        List<String> result = sol.binaryTreePaths(root);
        for(String s : result){
            System.out.println(s);
        }
    }
}
