/**
 * Author:Jack Yang
 * Date:2023/06/24
 * Description:122. Best Time to Buy and Sell Stock II
 */
public class Solution {
    public int maxProfit(int[] prices) {
        int result = 0;
        for (int i = 1 ; i < prices.length ; i++) {
            if (prices[i] - prices[i-1] > 0) {
                result+=(prices[i] - prices[i-1]);
            }
        }
        return result;
    }
}
