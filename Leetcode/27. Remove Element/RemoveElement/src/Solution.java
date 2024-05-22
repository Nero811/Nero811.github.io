import java.util.Arrays;

public class Solution {

    public static int removeElement(int[] nums, int val) {
        int result = 0;
        // fast index為優先遍歷，slow index為更新Array值的index
        for (int slow = 0, fast = 0; fast < nums.length; fast++) {
            if (nums[fast] != val) { // 思路 fast為主要遍歷，當遍歷的值 != val時，更新nums slow的值
                nums[slow++] = nums[fast];
                result++;
            }
        }
        return result;
    }

    public static void main(String[] args) throws Exception {
        int[] nums = new int[] { 0, 1, 2, 2, 3, 0, 4, 2 };
        int val = 2;
        System.out.println("result: " + removeElement(nums, val));
        // call by reference，removeElement method 已改變Array nums內的值
        Arrays.stream(nums).forEach(num -> {
            System.out.print(num + " ");
        });
    }
}
