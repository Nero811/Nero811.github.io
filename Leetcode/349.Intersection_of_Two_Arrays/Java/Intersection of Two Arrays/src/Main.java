import java.util.Arrays;

/**
 * Author:Jack Yang
 * Date:2023/06/22
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] num1 = {4,9,5};
        int[] num2 = {9,4,9,8,4};
        for (Integer i : sol.intersection(num1,num2)){
            System.out.println(i);
        }
    }
}
