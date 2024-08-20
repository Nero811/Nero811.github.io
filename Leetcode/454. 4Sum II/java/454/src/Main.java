import java.util.*;

public class Main {

    public static int fostaticurSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        int result = 0;

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0 ; i < nums1.length ; i++) {
            for (int j = 0 ; j < nums1.length ; j++) {
                if (!map.containsKey(nums1[i] + nums2[j])) {
                    map.put(nums1[i] + nums2[j], 1);
                } else {
                    map.put(nums1[i] + nums2[j], map.get(nums1[i] + nums2[j]) + 1);
                }

            }
        }

        for (int i = 0 ; i < nums3.length ; i++) {
            for (int j = 0 ; j < nums3.length ; j++) {
                if (map.containsKey(-(nums3[i] + nums4[j]))) {
                    result += map.get(-(nums3[i] + nums4[j]));
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[] nums1 = {1,2};
        int[] nums2 = {-2,-1};
        int[] nums3 = {-1,2};
        int[] nums4 = {0,2};

        System.out.println(fostaticurSumCount(nums1, nums2, nums3, nums4));
    }
}