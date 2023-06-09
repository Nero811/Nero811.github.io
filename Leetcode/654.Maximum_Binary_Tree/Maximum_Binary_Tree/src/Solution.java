import java.util.Comparator;
import java.util.Map;
import java.util.TreeMap;

/**
 * Author:Jack Yang
 * Date:2023/06/09
 * Description:Maximum Binary Tree
 */
public class Solution {
    public TreeNode travel(int leftIdx, int rightIdx, int[] nums){
        if (leftIdx >= rightIdx){
            if (leftIdx == rightIdx && leftIdx < nums.length){
                return new TreeNode(nums[leftIdx]);
            }
            return null;
        }
        int max = 0;
        int maxIdx = 0;
        for (int i = leftIdx ; i <= rightIdx ; i++){
            if (nums[i] > max){
                max = nums[i];
                maxIdx = i;
            }
        }
        TreeNode root = new TreeNode(max);
        root.left = travel(leftIdx, maxIdx-1, nums);
        root.right = travel(maxIdx+1, rightIdx, nums);
        return root;
    }
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        if (nums.length == 1)return new TreeNode(nums[0]);
        return travel(0,nums.length-1,nums);
    }
}

