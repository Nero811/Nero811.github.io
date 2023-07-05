import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/05
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        int k = 3, n = 9;
        Solution sol = new Solution();
        for (List<Integer> lt : sol.combinationSum3(k,n)) {
            for (Integer i : lt) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
