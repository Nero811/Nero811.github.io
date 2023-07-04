import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;


/**
 * Author:Jack Yang
 * Date:2023/07/04
 * Description:77. Combinations
 */
public class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    public void solution(int n, int k, int startIdx, LinkedList<Integer> lt) {
        if (lt.size() == k) {
            result.add(lt.stream().collect(Collectors.toList()));
            return;
        }
        for (int i = startIdx ; i <= n ; i++) {
            lt.add(i);
            solution(n, k, i + 1, lt);
            lt.removeLast();
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        LinkedList<Integer> lt = new LinkedList<>();
        solution(n, k, 1, lt);
        return result;
    }
}
