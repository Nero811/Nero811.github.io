import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

/**
 * Author:Jack Yang
 * Date:2023/06/22
 * Description:
 */
public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        int[] hash = new int[1001];
        for (Integer i : nums1){
            hash[i]++;
        }
        for (Integer j : nums2){
            if (hash[j] > 0){
                hash[j]--;
                if (!set.contains(j)){
                    set.add(j);
                }
            }
        }
        int[] result = new int[set.size()];
        int i = 0;
        for (Integer k : set){
            result[i] = k;
            i++;
        }
        return result;
    }
}
