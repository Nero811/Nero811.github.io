/**
 * Author:Jack Yang
 * Date:2023/07/13
 * Description:
 */
public class main {
    public static void main(String[] args) {
        Solution sol = new Solution();
    //    int[] nums = {2,3,1,2,4,3};
    //    int target = 7;
    //    int[] nums = {1,1,1,1,1,1,1,1};
    //    int target = 11;
    //    int[] nums = {12,28,83,4,25,26,25,2,25,25,25,12};
    //    int target = 213;
        int[] nums = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
        int target = 80;
        System.out.println(sol.minSubArrayLen(target, nums));
    }
}
