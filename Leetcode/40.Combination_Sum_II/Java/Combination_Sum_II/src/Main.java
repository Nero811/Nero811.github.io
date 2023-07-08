import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/09
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int target = 8;
        int[] candidates = {10,1,2,7,6,1,5};
        for (List<Integer> lt : sol.combinationSum2(candidates,target)) {
            for (Integer i : lt) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
