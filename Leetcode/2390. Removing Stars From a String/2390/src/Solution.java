import java.util.Deque;
import java.util.LinkedList;

public class Solution {
    public static String removeStars(String s) {
        StringBuilder sb = new StringBuilder();
        // 創建一個Deque儲存答案的index
        Deque<Integer> deque = new LinkedList<>();
        // 遍歷String當遇到*字元時，就將Deque最後一個字元移除
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '*') {
                deque.removeLast();
            } else {
                deque.add(i);
            }
        }
        // 遍歷Deque，構建結果字串
        while (!deque.isEmpty()) {
            sb.append(s.charAt(deque.removeFirst()));
        }
        return sb.toString();
    }

    public static void main(String[] args) throws Exception {
        String s = "erase*****";
        System.out.println(removeStars(s));
    }
}
