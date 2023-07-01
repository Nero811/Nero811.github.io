import org.w3c.dom.ls.LSOutput;

/**
 * Author:Jack Yang
 * Date:2023/07/01
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        char[] s = {'h','e','l','l','o'};
        sol.reverseString(s);
        for (char c : s) {
            System.out.print(c + " ");
        }
    }
}
