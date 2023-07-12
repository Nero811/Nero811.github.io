/**
 * Author:Jack Yang
 * Date:2023/07/12
 * Description:459. Repeated Substring Pattern
 */
public class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int[] nextTable = new int[s.length()];
        int j = 0;
        nextTable[0] = j;
        for (int i = 1 ; i < s.length() ; i++) {
            while (j > 0 && s.charAt(i) != s.charAt(j)) {
                j = nextTable[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                j++;
            }
            nextTable[i] = j;
        }

        if (nextTable[s.length() - 1] > 0 && s.length() % (s.length() - nextTable[s.length() - 1]) == 0) {
            return true;
        }
        return false;
    }
}
