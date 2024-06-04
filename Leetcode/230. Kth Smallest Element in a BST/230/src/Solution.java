

public class Solution {
    private static int result = 0;
    // 宣告一個計數器
    private static int cnt;
    /*
     * BST中，最左邊的節點就是最小的數字，因此向左子樹中序遍歷。
     * 找到最左邊的節點後，就可以開始用計數器紀錄節點數，當計數器=0時表示已找到符合題目條件的節點。
     * 時間複雜度O(N)
     */
    public static int sol(TreeNode root) {
        if (cnt == 0 || root == null) {
            return result;
        }
        sol(root.left);
        if (result > 0) {
            return result;
        }
        cnt--;
        if (cnt == 0) {
            result = root.val;
        }
        sol(root.right);
        return result;
    }
    public static int kthSmallest(TreeNode root, int k) {
        cnt = k;
        return sol(root);
    }

    public static void main(String[] args) throws Exception {
        TreeNode treeNode = new TreeNode(3);
        treeNode.left = new TreeNode(1);
        treeNode.right = new TreeNode(4);
        treeNode.left.right = new TreeNode(2);
        int k = 1;
        // TreeNode treeNode = new TreeNode(5);
        // treeNode.left = new TreeNode(3);
        // treeNode.right = new TreeNode(6);
        // treeNode.left.left = new TreeNode(2);
        // treeNode.left.right = new TreeNode(4);
        // treeNode.left.left.left = new TreeNode(1);
        // int k = 3;
        System.out.println("reuslt: " + kthSmallest(treeNode, k));
    }
}
