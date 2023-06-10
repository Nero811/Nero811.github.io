/**
 * Author:Jack Yang
 * Date:2023/06/10
 * Description:Merge Two Binary Trees
 */
public class Solution {
    public TreeNode travel(TreeNode root1, TreeNode root2){
        if (root1 == null && root2 ==null){
            return null;
        }
        TreeNode root = null;
        if (root1 != null && root2 != null){
            root = new TreeNode(root1.val + root2.val);
        }
        else if (root1 !=null && root2 == null){
            root = new TreeNode(root1.val);
        }
        else if (root1 == null && root2 != null){
            root = new TreeNode(root2.val);
        }

        if(root != null && root1 !=null && root2 != null)root.left = travel(root1.left,root2.left);
        else if(root != null && root1 == null && root2 != null)root.left = travel(null,root2.left);
        else if(root != null && root1 != null && root2 == null)root.left = travel(root1.left,null);

        if(root != null && root1 !=null && root2 != null)root.right = travel(root1.right,root2.right);
        else if(root != null && root1 == null && root2 != null)root.right = travel(null,root2.right);
        else if(root != null && root1 != null && root2 == null)root.right = travel(root1.right,null);

        return root;
    }
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        return this.travel(root1,root2);
    }
}
