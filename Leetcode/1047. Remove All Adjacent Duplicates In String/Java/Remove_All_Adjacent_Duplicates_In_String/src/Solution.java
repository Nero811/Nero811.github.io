import java.util.Stack;

/**
 * Author:Jack Yang
 * Date:2023/05/27
 * Description:Solution Class
 */
public class Solution {
    public String removeDuplicates(String s) {
        Stack<Character> st=new Stack<Character>();
        for(int i=0;i<s.length();i++){
            if(!st.empty() && s.charAt(i)==st.peek()){
                st.pop();
                continue;
            }
            st.push(s.charAt(i));
        }
        String result="";
        for(char c : st){
            result+=c;
        }
        return result;
    }
}
