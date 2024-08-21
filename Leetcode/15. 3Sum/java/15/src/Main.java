import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static List<List<Integer>> threeSum(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        Set<List<Integer>> set = new HashSet<>();

        for (Integer num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (int i = 0 ; i < nums.length ; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1 ; j < nums.length ; j++) {
                int sum = -(nums[i] + nums[j]);
                if (map.containsKey(sum)) {
                    int cnt = 1;
                    if (sum == nums[i]) cnt++;
                    if (sum == nums[j]) cnt++;
                    if (map.get(sum) >= cnt) {
                        List<Integer> lt = new LinkedList<>();
                        lt.add(nums[i]);
                        lt.add(nums[j]);
                        lt.add(sum);
                        Collections.sort(lt);
                        set.add(lt);
                    }
                }
            }
        }

        return new ArrayList<>(set);
    }

    public static void main(String[] args) {
        int[] nums = {-1,0,1,2,-1,-4};
        System.out.println(threeSum(nums));
    }
}