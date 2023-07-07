import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/07
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int target = 7;
        int[] candidates = {2,3,6,7};
        for (List<Integer> lt : sol.combinationSum(candidates, target)) {
            for (Integer i : lt) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
