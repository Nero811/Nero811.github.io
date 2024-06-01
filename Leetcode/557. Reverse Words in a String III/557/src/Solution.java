

public class Solution {
    public static String reverseWords(String s) {
        // 使用split先將String分組每個word成一個Array
        String[] array = s.split(" ");
        StringBuilder sb = new StringBuilder();
        // 遍歷Array並reverse每個word
        for (int i = 0 ; i < array.length ; i++) {
            for (int j = array[i].length() - 1 ; j >= 0 ; j--) {
                sb.append(array[i].charAt(j));
            }
            if (i != array.length - 1) {
                sb.append(' ');
            }
        }
        return sb.toString();
    }
    public static void main(String[] args) throws Exception {
        String s = "Let's take LeetCode contest";
        System.out.println(reverseWords(s));
    }
}
