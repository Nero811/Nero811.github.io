import java.util.Arrays;

public class Solution {

    public static int[] sortedSquares(int[] nums) {
        // 宣告兩個start、end，分別由Array最左、最右向中間遍歷
        // 思路因是有序數列，前後值取絕對值後一定比中間值大，因此只要比較前後值分別從Array最後依序放入就是答案
        int start = 0;
        int end = nums.length - 1;
        // 宣告一個空的result Array放置結果、Index為result Array的Index
        int index = nums.length - 1;
        int[] result = new int[nums.length];
        while (index >= 0) {
            // 比較前後值，依序放入result Array最後面，並且更新start、end、index
            if (Math.abs(nums[start]) < Math.abs(nums[end])) {
                result[index--] = nums[end] * nums[end];
                end--;
            } else {
                result[index--] = nums[start] * nums[start];
                start++;
            }
        }
        return result;
    }

    public static void main(String[] args) throws Exception {
        int[] nums = { -7, -3, 2, 3, 11 };
        int[] result = sortedSquares(nums);
        Arrays.stream(result).forEach(num -> {
            System.out.print(num + " ");
        });
    }
}
