import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/06/23
 * Description:15. 3Sum solution2
 */
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0 ; i < nums.length ; i++) {
            if (nums[0] > 0) return result;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.length - 1;
            while (right > left) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    result.add(Arrays.asList(nums[i],nums[left],nums[right]));
                    while (right > left && nums[right] == nums[right-1]) {
                        right--;
                    }
                    while (right > left && nums[left] == nums[left+1]) {
                        left++;
                    }
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
}
