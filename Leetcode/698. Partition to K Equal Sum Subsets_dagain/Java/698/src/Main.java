import java.util.Arrays;

public class Main {
    public  static boolean solution(int endIdx, int[] arr, int[] nums) {
        if (endIdx < 0) {
            return true;
        }

        for (int i = 0 ; i < arr.length ; i++) {
            if (arr[i] == nums[endIdx] || (endIdx > 0  && arr[i] - nums[endIdx] >= nums[0])) {
                arr[i] -= nums[endIdx];
                if (solution(endIdx - 1, arr, nums)) {
                    return true;
                }
                arr[i] += nums[endIdx];
            }
        }

        return false;
    }
    public static boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = Arrays.stream(nums).sum();
        if (sum % k != 0) {
            return  false;
        }
        int target = sum / k;
        int[] arr = new int[k];
        Arrays.fill(arr, target);
        return solution(nums.length - 1, arr, Arrays.stream(nums).sorted().toArray());
    }
    public static void main(String[] args) {
        int[] nums = {12,1,2,3,18,2,5,2,11,1};
        int k = 3;
        System.out.println(canPartitionKSubsets(nums, k));
    }
}