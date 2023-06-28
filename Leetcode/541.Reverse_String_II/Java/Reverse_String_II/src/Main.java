/**
 * Author:Jack Yang
 * Date:2023/06/28
 * Description:
 */
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        //String s = "abcdefg";
        String s = "jlnnxsetgcpsbhsfymrkhfursyissjnsocgdhgfxtxrlvugsaphqzxllwebukgatzfybprfmmfithphcxfsogsgqsnvckjvnskkc";
        System.out.println("s: " + s.length());
        //int k = 2;
        int k = 20;
        System.out.println(sol.reverseStr(s,k));
    }
}
