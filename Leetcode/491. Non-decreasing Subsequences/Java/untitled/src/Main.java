import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/18
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        // int[] nums = {4,6,7,7};
        // int[] nums = {4,4,3,2,1};
         int[] nums = {1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};
        for (List<Integer> lt : sol.findSubsequences(nums)) {
            System.out.println(lt);
        }
    }
}
