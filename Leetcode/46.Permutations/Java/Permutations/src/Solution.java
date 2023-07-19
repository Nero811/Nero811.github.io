import java.util.*;

/**
 * Author:Jack Yang
 * Date:2023/07/19
 * Description:46. Permutations
 */
public class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private LinkedList<Integer> path = new LinkedList<>();
    public void backTracking(int[] nums, int[] used) {
        if (path.size() == nums.length) {
            result.add(new ArrayList<>(path));
            return;
        }

        for (int i = 0 ; i < nums.length ; i++) {
            if (used[i] == 1) {
                continue;
            }
            path.add(nums[i]);
            used[i] = 1;
            backTracking(nums, used);
            used[i] = 0;
            path.removeLast();
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        Arrays.sort(nums);
        int[] used = new int[nums.length];
        backTracking(nums, used);
        return result;
    }
}
