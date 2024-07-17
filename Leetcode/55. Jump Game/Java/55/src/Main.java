public class Main {
    /*
    貪心算法
     */
    public static boolean canJump(int[] nums) {
        for (int cur = 0, fast = 0; fast < nums.length ; fast++) {
            int maxStep = 0;
            for (int i = 0 ; i <= nums[cur] ; i++) { // 遍歷當前可以走的最大步數，並更新最大步數
                if ((cur + i) <= nums.length - 1) {
                    if ((cur + nums[cur + maxStep]) < (cur + i + nums[cur + i])) { // 比較最大步數與當前步數的值
                        maxStep = i;
                        break; // 已更新最大步數，無須再找
                    }
                }
            }
            cur += maxStep; // 更新 cur index
            if (cur >= nums.length - 1 || cur + nums[cur] >= nums.length - 1) {
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        int[] nums = {5,9,3,2,1,0,2,3,3,1,0,0};
        System.out.println(canJump(nums));
    }
}