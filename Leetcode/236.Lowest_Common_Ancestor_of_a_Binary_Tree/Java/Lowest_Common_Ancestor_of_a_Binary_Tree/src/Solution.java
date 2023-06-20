/**
 * Author:Jack Yang
 * Date:2023/06/20
 * Description:236. Lowest Common Ancestor of a Binary Tree
 */
public class Solution {
    private boolean findP = false;
    private boolean findQ = false;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null){
            return null;
        }
        //System.out.println(root.val);
        TreeNode left = lowestCommonAncestor(root.left,p,q);
        TreeNode right = lowestCommonAncestor(root.right,p,q);
        if (root != null && (root.val == p.val || root.val == q.val)){
            if (root.val == p.val){
                if (!findP){
                    findP = true;
                    return root;
                }
            }
            else if (root.val == q.val){
                if (!findQ){
                    findQ = true;
                    return root;
                }
            }
        }
        if (findP || findQ){
            if (left != null && right != null && (findP && findQ)){
                return root;
            }
            else if(left != null && right == null){
                return left;
            }
            else if(left == null && right !=null){
                //        System.out.println(right.val);
                return right;
            }
        }
        return null;
    }
}
