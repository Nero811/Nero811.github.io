/**
 * Author:Jack Yang
 * Date:2023/07/30
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums1 = {1, 2};
        int[] nums2 = {-2, -1};
        int[] nums3 = {-1, 2};
        int[] nums4 = {0, 2};
//        int[] nums1 = {-1, -1};
//        int[] nums2 = {-1, 1};
//        int[] nums3 = {-1, 1};
//        int[] nums4 = {1, -1};
        System.out.println(sol.fourSumCount(nums1, nums2, nums3, nums4));
    }
}
