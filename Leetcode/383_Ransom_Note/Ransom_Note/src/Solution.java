/**
 * Author:Jack Yang
 * Date:2023/07/02
 * Description:383. Ransom Note
 */
public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] hash = new int[26];
        for (Character c : magazine.toCharArray()) {
            hash[(int)c - (int)'a']++;
        }
        for (Character c : ransomNote.toCharArray()) {
            if (hash[(int)c - (int)'a'] > 0) {
                hash[(int)c - (int)'a']--;
            }
            else {
                return false;
            }
        }
        return true;
    }
}
