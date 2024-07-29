public class Main {
    public static int numSquares(int n) {
        int[] dp = new int[n + 1];
        for (int i = 1 ; i <= n ; i++) {
            dp[i] = i;
        }

        for (int i = 2 ; i <= n ; i++) {
            for (int j = i - 1 ; j >= 1 ; j--) {
                if (i - j * j >= 0) {
                    dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
                }
            }
        }

        return dp[n];
    }
    public static void main(String[] args) {
        int n = 13;
        System.out.println(numSquares(n));
    }
}