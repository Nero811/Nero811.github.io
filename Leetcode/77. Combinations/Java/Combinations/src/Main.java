import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/04
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        int n = 4, k = 2;
        Solution sol = new Solution();
        for (List<Integer> lt : sol.combine(n,k)) {
            for (Integer i : lt) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
