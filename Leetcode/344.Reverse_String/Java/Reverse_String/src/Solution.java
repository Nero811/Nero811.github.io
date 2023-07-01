/**
 * Author:Jack Yang
 * Date:2023/07/01
 * Description:344. Reverse String
 */
public class Solution {
    public void reverseString(char[] s) {
        for (int i = 0, j = s.length - 1 ; i < j ; i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
}
