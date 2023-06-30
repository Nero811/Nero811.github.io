import java.util.ArrayList;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/06/30
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] words = {"bella","label","roller"};
        List<String> list = sol.commonChars(words);
        for (String s : list) {
            System.out.println(s);
        }
    }
}
