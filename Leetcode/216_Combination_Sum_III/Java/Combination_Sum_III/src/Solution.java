import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Author:Jack Yang
 * Date:2023/07/05
 * Description:216. Combination Sum III
 */
public class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private LinkedList<Integer> lt = new LinkedList<>();

    public void solution(int k, int n, int startIdx, int sum) {
        if (lt.size() == k) {
            if (sum == n) {
                result.add(lt.stream().collect(Collectors.toList()));
            }
            return;
        }
        for (int i = startIdx ; i <= 9 ; i++) {
            lt.add(i);
            solution(k, n, i + 1, sum + i);
            lt.removeLast();
        }
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        solution(k, n, 1, 0);
        return result;
    }
}
