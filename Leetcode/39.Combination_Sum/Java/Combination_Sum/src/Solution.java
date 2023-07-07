import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/07
 * Description:39. Combination Sum
 */
public class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private LinkedList path = new LinkedList();
    public void solution(int[] candidates, int target, int sum, int startIdx) {
        if (sum >= target) {
            if (sum == target) {
                result.add(new ArrayList<>(path));
            }
            return;
        }

        for (int i = startIdx ; i < candidates.length ; i++) {
            path.add(candidates[i]);
            solution(candidates, target, sum + candidates[i], i);
            path.removeLast();
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        int[] newCandidates = Arrays.stream(candidates).sorted().toArray();
        solution(newCandidates, target, 0, 0);
        return result;
    }
}
