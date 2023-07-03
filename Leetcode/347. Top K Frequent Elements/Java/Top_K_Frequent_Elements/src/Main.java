/**
 * Author:Jack Yang
 * Date:2023/07/03
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        int[] nums = {4,1,-1,2,-1,2,3};
        int k = 2;
        Solution sol = new Solution();
        for (Integer i : sol.topKFrequent(nums,k)) {
            System.out.println(i);
        }
    }
}
