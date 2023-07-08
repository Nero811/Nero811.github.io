import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/09
 * Description:40. Combination Sum II
 */
public class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private LinkedList path = new LinkedList();
    public void solution(int[] candidates, int target, int sum, int startIdx, int[] used) {
        if (sum >= target) {
            if (sum == target){
                result.add(new ArrayList<>(path));
            }
            return;
        }

        for (int i = startIdx ; i < candidates.length ; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i-1] == 0) {
                continue;
            }
            path.add(candidates[i]);
            used[i] = 1;
            solution(candidates, target, sum + candidates[i], i + 1 ,used);
            used[i] = 0;
            path.removeLast();
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        int[] used = new int[candidates.length];
        solution(candidates, target, 0, 0, used);
        return result;
    }
}
