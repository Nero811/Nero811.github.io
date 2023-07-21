import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/21
 * Description:47. Permutations II
 */
public class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private LinkedList<Integer> path = new LinkedList<>();
    public void backTracking(int[] nums, int[] used) {
        if (path.size() == nums.length) {
            result.add(new ArrayList<>(path));
            return;
        }

        HashSet set = new HashSet<>();
        for (int i = 0 ; i < nums.length ; i++) {
            if (set.contains(nums[i]) || used[i] == 1) {
                continue;
            }
            path.add(nums[i]);
            set.add(nums[i]);
            used[i] = 1;
            backTracking(nums, used);
            used[i] = 0;
            path.removeLast();
        }
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        int[] used = new int[nums.length];
        backTracking(nums, used);
        return result;
    }
}
