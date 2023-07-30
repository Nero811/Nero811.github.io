import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/30
 * Description:454. 4Sum II
 */
public class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int result = 0;
        for (Integer i : nums1) {
            for (Integer j : nums2) {
                if (!map.containsKey(i + j)) {
                    map.put(i + j, 1);
                }
                else {
                    map.put((i + j), map.get(i + j) + 1);
                }
            }
        }

        for (Integer i : nums3) {
            for (Integer j : nums4) {
                if (map.containsKey(0 - (i + j))) {
                    result += map.get(0 - (i + j));
                }
            }
        }

        return result;
    }
}
