import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/13
 * Description:209. Minimum Size Subarray Sum
 */
public class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int result = 500000;
        int j = 0;
        int sum = 0;
        for (int i = 0 ; i < nums.length ; i++) {
            sum+=nums[i];
            while (sum >= target) {
                result = Math.min(result, (i - j) + 1);
                sum-=nums[j];
                j++;
            }
        }
        if (result == 500000) {
            return 0;
        }
        return result;
    }
}
