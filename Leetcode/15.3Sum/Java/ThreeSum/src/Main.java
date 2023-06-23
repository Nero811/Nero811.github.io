import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/06/23
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        int[] nums = {-1,0,1,2,-1,-4};
        Solution sol = new Solution();
        List<List<Integer>> result = sol.threeSum(nums);
        for (List<Integer> lt : result){
            for (Integer i : lt){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
