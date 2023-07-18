import java.util.*;

/**
 * Author:Jack Yang
 * Date:2023/07/18
 * Description:491. Non-decreasing Subsequences
 */
public class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private LinkedList<Integer> path = new LinkedList<>();
    public void backTracking(int[] nums, int startIdx) {
        if (path.size() >= 2) {
            result.add(new ArrayList<>(path));
        }

        if (startIdx > nums.length - 1) {
            return;
        }

        List<Integer> used = new ArrayList<>();
        for (int i = startIdx ; i < nums.length ; i++) {
            if ((!path.isEmpty()) && (nums[i] < path.get(path.size() - 1)) || used.contains(nums[i])) {
                continue;
            }
            used.add(nums[i]);
            path.add(nums[i]);
            backTracking(nums, i + 1);
            path.removeLast();
        }
    }
    public List<List<Integer>> findSubsequences(int[] nums) {
        backTracking(nums, 0);
        return result;
    }
}
