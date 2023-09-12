/**
 * Author:Jack Yang
 * Date:2023/09/12
 * Description:
 */
public class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        }
        if (root.val == key) {
            if (root.left == null && root.right == null) {
                return null;
            }
            else if (root.left != null && root.right != null) {
                TreeNode cur = root.left;
                while (cur.right != null) {
                    cur = cur.right;
                }
                cur.right = root.right;
                return root.left;
            }
            else if (root.left != null && root.right == null) {
                return root.left;
            }
            else if (root.left == null && root.right != null) {
                return root.right;
            }
        }
        if (root.val > key) {
            root.left = this.deleteNode(root.left, key);
        }
        if (root.val < key) {
            root.right = this.deleteNode(root.right, key);
        }
        return root;
    }
}
