import java.util.ArrayList;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/10
 * Description:93. Restore IP Addresses
 */
public class Solution {
    private List<String> result = new ArrayList<>();
    public boolean isValidIP(String s, int starIdx, int endIdx) {
        if (starIdx > s.length() - 1) {
            return false;
        }
        if (s.charAt(starIdx) == '0' && (endIdx - starIdx) > 0) {
            return false;
        }
        String subString = s.substring(starIdx, endIdx + 1);
        Long l = Long.parseLong(subString);
        if (l > 255) {
            return false;
        }
        return true;
    }
    public void solution(StringBuilder sb, int startIdx, int spotCnt) {
        String s = sb.toString();
        if (spotCnt == 3) {
            if (isValidIP(s, startIdx, s.length() - 1)) {
                result.add(s);
            }
            return;
        }

        int size = sb.length();

        for (int i = startIdx ; i < size ; i++) {
            if (isValidIP(s, startIdx, i)) {
                sb.insert(i + 1, '.');
                solution(sb, i + 2, spotCnt+1);
                sb.deleteCharAt(i + 1);
            }
            else {
                break;
            }
        }
    }
    public List<String> restoreIpAddresses(String s) {
        StringBuilder sb = new StringBuilder(s);
        solution(sb, 0 , 0);
        return result;
    }
}
