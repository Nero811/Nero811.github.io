import java.util.*;
import java.util.stream.Collectors;

/**
 * Author:Jack Yang
 * Date:2023/06/23
 * Description:15. 3Sum
 */
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        HashMap<Integer,Integer> map = new HashMap<>();
        for (int i = 0 ; i < nums.length ; i++) {
            map.put(i,nums[i]);
        }
        for (int i = 0 ; i < nums.length ; i++) {
            int num1 = map.get(i);
            map.remove(i);
            for (int j = nums.length -1  ; j > i ; j--){
                int num2 = map.get(j);
                map.remove(j);
                int num3 = 0 - (num1 + num2);
                if (map.containsValue(num3)){
                    List<Integer> list = new ArrayList<>(Arrays.asList(num1,num2,num3));
                    Collections.sort(list);
                    if (!result.contains(list)) {
                        result.add(list);
                    }
                }
                map.put(j,nums[j]);
            }
            map.put(i,nums[i]);
        }
        return result;
    }
}
