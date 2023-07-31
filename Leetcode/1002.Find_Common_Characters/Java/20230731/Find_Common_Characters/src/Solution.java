import java.util.ArrayList;
import java.util.List;

/**
 * Author:Jack Yang
 * Date:2023/07/31
 * Description:1002. Find Common Characters
 */
public class Solution {
    public List<String> commonChars(String[] words) {
        int[] hash = new int[26];
        for (int i = 0 ; i < words[0].length() ; i++) {
            hash[words[0].charAt(i) - 'a']++;
        }

        for (int i = 1 ; i < words.length ; i++) {
            int[] hash2 = new int[26];
            for (int j = 0 ; j < words[i].length() ; j++) {
                int count = words[i].charAt(j) - 'a';
                hash2[count]++;
            }
            for (int k = 0 ; k < 26 ; k++) {
                hash[k] = Math.min(hash[k], hash2[k]);
            }
        }

        List<String> result = new ArrayList<>();
        for (int i = 0 ; i < 26 ; i++) {
            while (hash[i] > 0) {
                result.add(String.valueOf((char)(i + 97)));
                hash[i]--;
            }
        }

        return result;
    }
}
