/**
 * Author:Jack Yang
 * Date:2023/09/02
 * Description:Convert Sorted Array to Binary Search Tree
 */
public class Solution {
    public TreeNode travel(int[] nums, int left, int right) {
        if (left > right) {
            return null;
        }
        int mid = (left + right) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = travel(nums, left, mid - 1);
        node.right = travel(nums, mid + 1 ,right);
        return node;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return travel(nums, 0, nums.length - 1);
    }
}
