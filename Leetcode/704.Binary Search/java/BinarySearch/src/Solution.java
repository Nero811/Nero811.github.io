public class Solution {
    public static int search(int[] nums, int target) {
        // 宣告 left 初始化為 Array index 0
        int left = 0;
        // 宣告 right 初始化為 Array index Array 長度 - 1
        int right = nums.length - 1;
        while (left <= right) {
            // 宣告mid為left、right的中間值
            int mid = left + ((right - left) / 2);
            // 找到target，return結果
            if (nums[mid] == target) {
                return mid;
            }
            // 思路為target在left、right的區間當中
            if (nums[mid] < target) { // 表示target在left右方
                left = mid + 1;
            } else if (nums[mid] > target) { // 表示target在right左方
                right = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) throws Exception {
        int[] nums = new int[] { -1,0,3,5,9,12 };
        int target = 12;
        System.out.println("Result =: " + search(nums, target));
    }
}
