import java.util.ArrayList;

public class Solution {
    public static String convert(String s, int numRows) {
        int cnt = 1; // 表示Array第幾層
        int flag = 0; // flag = 0表示Array遍歷向下，cnt++。flag = 1 表示Array遍歷向上，cnt--
        // 宣告一個二維Array，長為numsRows，並初始化
        ArrayList<Character>[] list = new ArrayList[numRows];
        for (int i = 0; i < numRows; i++) {
            list[i] = new ArrayList<Character>();
        }
        /*
         * 思路是由上到下，由左而右遍歷String，並依序將char放入二維Array，
         * 最後將Array結果組成字串就是答案。
         * 時間複雜度O(n)
         */
        for (int i = 0; i < s.length(); i++) {
            list[cnt - 1].add(s.charAt(i));
            if (cnt == 1) { // 表示為首列
                if (flag == 1) {
                    flag = 0;
                }
                if (numRows != 1) {
                    cnt++;
                }
            } else if (cnt > 1 && cnt < numRows) { // 首列與尾列之間
                if (flag == 0) {
                    cnt++;
                } else if (flag == 1) {
                    cnt--;
                }
            } else if (cnt == numRows) { // 表示為尾列
                flag = 1;
                cnt--;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            list[i].stream().forEach(element -> {
                sb.append(String.valueOf(element));
            });
        }

        return sb.toString();
    }

    public static void main(String[] args) throws Exception {
        String s = "AB";
        int numRows = 1;
        System.out.println(convert(s, numRows));
    }
}
