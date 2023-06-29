/**
 * Author:Jack Yang
 * Date:2023/06/29
 * Description:151. Reverse Words in a String
 */
public class Solution {
    public String reverseWords(String s) {
        int end = s.length();
        int start = 0;
        String result = "";
        for (int i = s.length()-1 ; i >= 0 ; i--) {
            if (s.charAt(i) != ' ') {
                if (result.length() > 0) {
                    result += " ";
                }
                end = i;
                while (i >= 0 && s.charAt(i) != ' ') {
                    i--;
                }
                start = i + 1;
                result += s.substring(start,end + 1);
            }
        }
        return result;
    }
}
