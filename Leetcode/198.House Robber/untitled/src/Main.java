public class Main {
    public static int rob(int[] nums) {
        if (nums.length <= 2) {
            if (nums.length == 1) {
                return nums[0];
            }
            return Math.max(nums[0], nums[1]);
        }
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        int max = Math.max(dp[0], dp[1]);
        for (int i = 2; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
            max = Math.max(max, dp[i]);
        }

        return max;
    }

    public static void main(String[] args) {
        int[] nums = {2,1,1,2};
        System.out.println(rob(nums));
    }
}