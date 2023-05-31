import java.util.ArrayList;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/05/31
 * Description:Solution Class
 */
public class Solution {
    private List<String> result;
    public int travel(TreeNode root,String path){
        if(root==null){
            return -1;
        }
        path+=root.val;
        if(root.left != null || root.right != null){
            path += "->";
        }
        int left = travel(root.left,path);
        int right = travel(root.right,path);
        if(left == -1 && right == -1) {
            result.add(path);
        }
        return 0;
    }
    public List<String> binaryTreePaths(TreeNode root) {
        result = new ArrayList<>();
        if(root==null)return result;
        this.travel(root,"");
        return result;
    }
}
