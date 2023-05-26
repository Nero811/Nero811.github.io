import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer>mp=new HashMap<>();
        int[] result=new int[2];
        mp.putIfAbsent(nums[0],0);
        for(int i=1;i<nums.length;i++){
            if(mp.get(target-nums[i])!=null){
                if(mp.get(target-nums[i])==target-nums[i]){
                    result[0]=mp.get(target-nums[i]);
                    result[1]=i;
                    return result;
                }
                result[0]=i;
                result[1]=mp.get(target-nums[i]);
                return result;
            }
            mp.putIfAbsent(nums[i],i);
        }
        return result;
    }
    public static void main(String[] args) {
//        int[] nums={2,7,11,15};
//        int target=9;
//        int[] nums={3,3};
          int[] nums={3,2,4};
          int target=6;
        Solution sol=new Solution();
        int[] result=sol.twoSum(nums,target);
        for(int i : result){
            System.out.println(i);
        }
    }
}
