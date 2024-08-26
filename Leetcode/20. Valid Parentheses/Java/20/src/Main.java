import java.util.Stack;

public class Main {

    public static boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == ')' && !st.isEmpty() && st.peek() == '(') {
                st.pop();
                continue;
            } else if (ch == ']' && !st.isEmpty() && st.peek() == '[') {
                st.pop();
                continue;
            } else if (ch == '}' && !st.isEmpty() && st.peek() == '{') {
                st.pop();
                continue;
            }
            st.push(ch);
        }
        if (!st.isEmpty()) {
            return false;
        }

        return true;
    }

    public static void main(String[] args) {
        String s = "([])";
        System.out.println(isValid(s));
    }
}