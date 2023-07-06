import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/06
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        String digits = "23";
        Solution sol = new Solution();
        for (String s : sol.letterCombinations(digits)) {
            System.out.println(s);
        }
    }
}
