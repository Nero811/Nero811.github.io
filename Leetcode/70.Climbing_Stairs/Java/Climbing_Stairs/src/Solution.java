/**
 * Author:Jack Yang
 * Date:2023/07/31
 * Description:70. Climbing Stairs
 */
public class Solution {
    public int climbStairs(int n) {
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        if (n <= 2) {
            return dp[n];
        }
        for (int i = 3 ; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
