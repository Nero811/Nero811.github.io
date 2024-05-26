
public class Solution {
    public static int minSubArrayLen(int target, int[] nums) {
        int sum = 0;
        int result = Integer.MAX_VALUE;
        /*
         * 宣告兩個slow、fast index，fast先遍歷整個Array找到符合target的區間，
         * slow再遍歷找到最小的target區間
         */
        for (int slow = 0, fast = 0; fast < nums.length; fast++) {
            sum += nums[fast];
            /*
             * 由fast先遍歷找到slow、fast index間的target區間，
             * slow再遍歷找尋最小區間，當while迴圈結束，表示找到了最小區間
             */
            while (sum >= target) {
                sum -= nums[slow];
                result = (fast - slow + 1);
                slow++;
            }
        }
        if (result == Integer.MAX_VALUE) {
            return 0;
        } else {
            return result;
        }
    }

    public static void main(String[] args) throws Exception {
        int[] nums = { 10, 5, 13, 4, 8, 4, 5, 11, 14, 9, 16, 10, 20, 8 };
        int target = 80;
        System.out.println("result: " + minSubArrayLen(target, nums));
    }
}
