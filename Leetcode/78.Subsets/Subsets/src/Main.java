import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/16
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1,2,3};
        for (List<Integer> lt : sol.subsets(nums)) {
            System.out.println(lt);
        }
    }
}
