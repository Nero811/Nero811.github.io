/**
 * Author:Jack Yang
 * Date:2023/06/21
 * Description:Lowest Common Ancestor of a Binary Search Tree
 */
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while (root != null){
            if (root.val > p.val && root.val > q.val){
                root = root.left;
            }
            else if (root.val < p.val && root.val < q.val){
                root = root.right;
            }
            else {
                return root;
            }
        }
        return root;
    }
}
