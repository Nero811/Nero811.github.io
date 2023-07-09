import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/09
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "efe";
        for (List<String> lt : sol.partition(s)) {
            for (String words : lt) {
                System.out.println(words);
            }
            System.out.println();
        }
    }
}
