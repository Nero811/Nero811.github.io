import java.util.*;

/**
 * Author:Jack Yang
 * Date:2023/07/06
 * Description:17. Letter Combinations of a Phone Number
 */

public class Solution {
    private LinkedList<Character> path = new LinkedList<>();
    private List<String> result = new ArrayList<>();
    public void solution(char[] digits, Map<Character,String> map, int startIdx) {
        if (path.size() == digits.length) {
            String s = "";
            for (Character c : path) {
                s+=c;
            }
            result.add(s);
            return;
        }

        for (int i = startIdx ; i < digits.length ; i++) {
            for (int j = 0 ; j < map.get(digits[i]).length() ; j++) {
                path.add(map.get(digits[i]).charAt(j));
                solution(digits, map, startIdx + 1);
                path.removeLast();
            }
            break;
        }
    }
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return result;
        Map<Character,String> map = new HashMap<>();
        map.put('2',"abc");
        map.put('3',"def");
        map.put('4',"ghi");
        map.put('5',"jkl");
        map.put('6',"mno");
        map.put('7',"pqrs");
        map.put('8',"tuv");
        map.put('9',"wxyz");
        solution(digits.toCharArray(), map, 0);
        return result;
    }
}
