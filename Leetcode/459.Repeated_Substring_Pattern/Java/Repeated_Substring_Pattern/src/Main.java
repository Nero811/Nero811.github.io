/**
 * Author:Jack Yang
 * Date:2023/07/12
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        String s = "abac";
        Solution sol = new Solution();
        if (sol.repeatedSubstringPattern(s)) {
            System.out.println("true");
        }
        else {
            System.out.println("false");
        }
    }
}
