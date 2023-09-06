/**
 * Author:Jack Yang
 * Date:2023/09/06
 * Description:
 */
public class Solution {
    // 宣告遞迴函式
    public boolean travel(TreeNode leftTree, TreeNode rightTree) {
        // 兩個結點都是空結點表示為真
        if (leftTree == null && rightTree == null) {
            return true;
        }
        // 兩個結點有一個為空，另一個不為空表示沒有對稱
        else if ((leftTree == null && rightTree != null) || (leftTree != null && rightTree == null)){
            return false;
        }
        // 兩結點value不一樣表示沒有對稱
        else if (leftTree.val != rightTree.val) {
            return false;
        }

        boolean left = travel(leftTree.left, rightTree.right);
        boolean right = travel(leftTree.right, rightTree.left);
        return left && right;
    }
    public boolean isSymmetric(TreeNode root) {
        return travel(root.left, root.right);
    }
}
