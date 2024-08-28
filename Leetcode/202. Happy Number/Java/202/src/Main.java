import java.util.HashMap;
import java.util.Map;

public class Main {

    public static boolean isHappy(int n) {
        String num = Integer.toString(n);
        Map<Integer, Integer> map = new HashMap<>();
        while (true) {
            int sum = 0;
            for (int i = num.length() - 1 ; i >= 0 ; i--) {
                int number = Character.getNumericValue(num.charAt(i));
                sum += (number * number);
            }
            if (!map.isEmpty() && map.containsKey(sum)) {
                return false;
            }
            map.put(sum, 1);
            if (sum == 1) {
                return true;
            }
            n = sum;
            num = Integer.toString(n);
        }
    }

    public static void main(String[] args) {
        int n = 2;
        System.out.println(isHappy(n));
    }
}