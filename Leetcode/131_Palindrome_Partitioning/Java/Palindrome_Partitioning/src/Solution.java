import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;
import java.util.stream.Collectors;

/**
 * Author:Jack Yang
 * Date:2023/07/09
 * Description:131. Palindrome Partitioning
 */
public class Solution {
    private List<List<String>> result = new ArrayList<>();
    private LinkedList<String> path = new LinkedList<>();
    public boolean isPalindrome (String word) {
        if (word.length() == 1) {
            return true;
        }
        char[] charArray = word.toCharArray();
        for (int i = 0, j = charArray.length - 1 ; i < j ; i++, j--) {
            if (charArray[i] != charArray[j]) {
                return false;
            }
        }
        return true;
    }
    public void solution(char[] charArray, int startIdx) {

        if (startIdx >= charArray.length) {
            if (!path.isEmpty()) {
                result.add(new ArrayList<>(path));
            }
            return;
        }

        String word = "";
        for (int i = startIdx ; i < charArray.length ; i++) {
            word+=charArray[i];
            if (isPalindrome(word)) {
                path.add(word);
            }
            else {
                continue;
            }
            solution(charArray, i + 1);
            if (!path.isEmpty()) {
                path.removeLast();
            }
        }
    }
    public List<List<String>> partition(String s) {
        solution(s.toCharArray(), 0);
        return result;
    }
}
