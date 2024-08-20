import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class Main {

    public static void sol(int n, int k, int start, Stack<Integer> st, List<List<Integer>> result) {
        if (st.size() == k) {
            result.add(new ArrayList<>(st));
            return;
        }

        for (int i = start; i <= n; i++) {
            st.add(i);
            sol(n, k, i + 1, st, result);
            st.pop();
        }

        return;
    }

    public static List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new LinkedList<>();
        sol(n, k, 1, new Stack<>(), result);
        return result;
    }

    public static void main(String[] args) {
        int n = 4;
        int k = 2;
        System.out.println(combine(n, k));
    }
}