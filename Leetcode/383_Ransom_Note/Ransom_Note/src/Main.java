/**
 * Author:Jack Yang
 * Date:2023/07/02
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String magazine = "aab";
        String ransomNote = "aa";
        if (sol.canConstruct(ransomNote,magazine)) {
            System.out.println("true");
        }
        else {
            System.out.println("false");
        }
    }
}
