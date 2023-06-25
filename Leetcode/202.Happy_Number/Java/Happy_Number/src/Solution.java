import java.util.HashSet;
import java.util.Set;

/**
 * Author:Jack Yang
 * Date:2023/06/25
 * Description:
 */
public class Solution {
    public int findHappy(int num) {
        int sum = 0;
        while (num > 0) {
            sum += Math.pow(num%10,2);
            num/=10;
        }
        return sum;
    }
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();
        while (!set.contains(n)) {
            set.add(n);
            n = findHappy(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
    }
}
