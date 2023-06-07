/**
 * Author:Jack Yang
 * Date:2023/06/07
 * Description:
 */
public class Main {
    public static void main(String[] args) {
       // String s = "()[]{}";
        String s = "()[}[}";
        Solution sol = new Solution();
        if (sol.isValid(s)){
            System.out.println("True");
        }
        else{
            System.out.println("False");
        }
    }
}
