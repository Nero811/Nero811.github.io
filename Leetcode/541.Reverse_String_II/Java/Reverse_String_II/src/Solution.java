/**
 * Author:Jack Yang
 * Date:2023/06/28
 * Description:
 */
public class Solution {
    public String reverse(String s, int start, int end) {
        char[] charArray = s.toCharArray();
        for (int i = start, j = end; i < j ; i++, j--) {
            char tmp = charArray[i];
            charArray[i] = charArray[j];
            charArray[j] = tmp;
        }
        return new String(charArray);
    }
    public String reverseStr(String s, int k) {
        int j = 0;
        int cnt = 1;
        for (int i = 0 ; i < s.length() ; i++) {
            if (cnt == 2*k) {
                s = this.reverse(s, j, j + k-1);
                j = i+1;
                cnt = 0;
            }
            else if (i == s.length()-1 && (i - j < k)) {
                s = this.reverse(s, j, i);
            }
            else if (i == s.length()-1 && (i - j) >= k-1) {
                s = this.reverse(s, j, j+k-1);
            }
            cnt++;
        }
        return s;
    }
}