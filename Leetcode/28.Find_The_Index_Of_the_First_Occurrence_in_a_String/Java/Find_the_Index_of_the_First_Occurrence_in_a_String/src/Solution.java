/**
 * Author:Jack Yang
 * Date:2023/06/08
 * Description:Find the Index of the First Occurrence in a String
 */
public class Solution {
    public void getNext(int[] next,String needle){
        int j = 0;
        next[0] = j;
        for(int i = 1 ; i < needle.length() ; i++){
            while (j > 0 && needle.charAt(j) != needle.charAt(i)){
                j = next[j-1];
            }
            if(needle.charAt(j) == needle.charAt(i)){
                j++;
            }
            next[i]=j;
        }
    }

    public int strStr(String haystack, String needle) {
        int[] next = new int[needle.length()];
        this.getNext(next,needle);
        int j = 0;
        for(int i = 0 ; i < haystack.length() ; i++){
            while (j > 0 && haystack.charAt(i) != needle.charAt(j)){
                j = next[j-1];
            }
            if (haystack.charAt(i) == needle.charAt(j)){
                if (j == needle.length()-1){
                    return i - (needle.length()-1);
                }
                j++;
            }
        }
        return -1;
    }
}
