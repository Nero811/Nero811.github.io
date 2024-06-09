import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class Solution {
    private static List<String> result = new LinkedList<>();
    public static void sol(String str, int start, int length) {
        /*
         * 結束條件，當String長度 = pair長度時
         */
        if (str.length() == length) {
            Stack<Character> st = new Stack<>();
            // 判斷是否為合法的String
            for (int i = 0 ; i < length ; i++) {
                if (str.charAt(i) == '(') {
                    st.push(str.charAt(i));
                } else if (str.charAt(i) == ')' && !st.empty() && st.peek() == '(') {
                    st.pop();
                } else if (str.charAt(i) == ')' && (st.empty() || st.peek() != '(')) {
                    return;
                }
            }
            if (st.empty()) {
                result.add(str);
            }
            return;
        }
        /*
         * 遍歷所有的可能結果，並回朔String
         */
        for (int i = start; i < length; i++) {
            sol(str + ")", i + 1, length);
            sol(str + "(", i + 1, length);
        }
    }
    public static List<String> generateParenthesis(int n) {
        sol("", 0, n * 2);
        return result;
    }

    public static void main(String[] args) throws Exception {
        int n = 1;
        generateParenthesis(n);
        result.forEach(str -> {
            System.out.print(str + " ");
        });
    }
}
