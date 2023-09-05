/**
 * Author:Jack Yang
 * Date:2023/09/05
 * Description:
 */
public class Solution {
    public boolean repeatedSubstringPattern(String s) {
        // 使用kmp演算法解題
        int j = 0;
        // 定義一個next table
        int[] next = new int[s.length()];
        next[0] = j;
        // 將next table賦予值
        for (int i = 1; i < s.length() ; i++) {
            while (j > 0 && s.charAt(j) != s.charAt(i)) {
                j = next[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                j++;
            }
            next[i] = j;
        }

        if (next[s.length() - 1] > 0 && s.length() % (s.length() - (next[s.length() - 1])) == 0) {
            return true;
        } else {
            return false;
        }
    }
}
