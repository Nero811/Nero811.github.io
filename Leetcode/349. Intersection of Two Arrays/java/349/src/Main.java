import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {

    public static int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        Set<Integer> result = new HashSet<>();
        Arrays.stream(nums1).forEach(set::add);
        Arrays.stream(nums2).forEach(num -> {
            if (set.contains(num)) {
                result.add(num);
            }
        });

        return result.stream().mapToInt(Integer::intValue).toArray();
    }

    public static void main(String[] args) {
        int[] nums1 = {4,9,5};
        int[] nums2 = {9,4,9,8,4};
        Arrays.stream(intersection(nums1, nums2)).forEach(num -> {
            System.out.println(num);
        });
    }
}