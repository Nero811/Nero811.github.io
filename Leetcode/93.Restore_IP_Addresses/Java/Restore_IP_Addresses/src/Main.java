/**
 * Author:Jack Yang
 * Date:2023/07/10
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        // String s = "25525511135";
        // String s ="101023";
        // String s = "0000";
        String s = "0279245587303";
        for (String string : sol.restoreIpAddresses(s)) {
            System.out.println(string);
        }
    }
}
