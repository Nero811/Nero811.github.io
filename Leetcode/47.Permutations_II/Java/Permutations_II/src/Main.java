import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/21
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        int[] nums = {1,1,2};
        // int[] nums = {1,2,3};
        // int[] nums = {3,3,0,3};
        Solution sol = new Solution();
        for (List<Integer> lt : sol.permuteUnique(nums)) {
            System.out.println(lt);
        }
    }
}
