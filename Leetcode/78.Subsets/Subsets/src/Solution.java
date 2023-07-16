import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/16
 * Description:78. Subsets
 */
public class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private LinkedList<Integer> path = new LinkedList<>();
    public void backTracking(int[] nums, int startIdx) {
        result.add(new ArrayList<>(path));
        if (path.size() == nums.length) {
            return;
        }

        for (int i = startIdx ; i < nums.length ; i++) {
            path.add(nums[i]);
            backTracking(nums, i + 1);
            path.removeLast();
        }
    }
    public List<List<Integer>> subsets(int[] nums) {
        backTracking(nums, 0);
        return result;
    }
}
