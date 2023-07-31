import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/31
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        // String[] words = {"bella","label","roller"};
        String[] words = {"cool","lock","cook"};
        Solution sol = new Solution();
        for (String s : sol.commonChars(words)) {
            System.out.println(s);
        }
    }
}
