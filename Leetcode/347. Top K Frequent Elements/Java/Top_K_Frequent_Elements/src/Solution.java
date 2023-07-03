import javax.swing.*;
import java.security.KeyStore;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * Author:Jack Yang
 * Date:2023/07/03
 * Description:347. Top K Frequent Elements
 */
public class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<>();
        for (Integer i : nums) {
            if (!map.containsKey(i)) {
                map.put(i,1);
            }
            else {
                map.put(i,map.get(i)+1);
            }
        }
        LinkedHashMap<Integer,Integer> sortedMap =
                map.entrySet().stream()
                        .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
                        .collect((Collectors.toMap(
                                Map.Entry::getKey,
                                Map.Entry::getValue,
                                (oldValue, newValue) -> oldValue, LinkedHashMap::new
                        )));


        int[] result = new int[k];
        int i = 0;
        for (Map.Entry<Integer,Integer> m : sortedMap.entrySet()) {
            if (i <= k - 1) {
                result[i] = m.getKey();
            }
            i++;
        }
        return result;
    }
}
