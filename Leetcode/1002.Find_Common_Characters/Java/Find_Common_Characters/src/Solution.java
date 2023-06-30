import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * Author:Jack Yang
 * Date:2023/06/30
 * Description:1002. Find Common Characters
 */
public class Solution {
    public int[] updateHash(int[] hash,String words) {
        int[] newHash = new int[27];
        for (Character c : words.toCharArray()) {
            newHash[(int) c - (int) 'a']++;
        }
        for (int i = 0 ; i < 27 ; i++) {
            hash[i] = Math.min(hash[i],newHash[i]);
        }
        return hash;
    }
    public List<String> commonChars(String[] words) {
        if (words.length == 1) {
            return Arrays.stream(words).collect(Collectors.toList());
        }
        int[] hash = new int[27];
        List<String> result = new ArrayList<>();
        for (Character c : words[0].toCharArray()) {
            hash[ (int) c - (int) 'a']++;
        }
        for (int i = 1 ; i < words.length ; i++) {
            hash = this.updateHash(hash,words[i]);
        }
        for (int i = 0 ; i < hash.length ; i++){
            while (hash[i] > 0) {
                char c = (char) (i + 'a') ;
                result.add(String.valueOf(c));
                hash[i]--;
            }
        }
        return result;
    }
}
