public class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length())return false;
        int[] hash=new int[27];
        for(int i=0;i<s.length();i++){
            hash[s.charAt(i)-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(hash[t.charAt(i)-'a']>0)hash[t.charAt(i)-'a']--;
            else return false;
        }
        return true;
    }
}
