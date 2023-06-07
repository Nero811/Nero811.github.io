import java.util.Stack;

/**
 * Author:Jack Yang
 * Date:2023/06/07
 * Description:20. Valid Parentheses
 */
public class Solution {
    public boolean isValid(String s) {
        if(s.length() == 1) return false;
        Stack<Character> st = new Stack<>();
        for(int i=0; i < s.length() ; i++){
            if(!st.empty()){
                if(s.charAt(i)==')'){
                   if(st.peek() != '('){
                       return false;
                   }
                   else {
                       st.pop();
                   }
                }
                else if(s.charAt(i)=='}'){
                    if(st.peek() != '{'){
                        return false;
                    }
                    else {
                        st.pop();
                    }
                }
                else if(s.charAt(i)==']'){
                    if(st.peek() != '['){
                        return false;
                    }
                    else {
                        st.pop();
                    }
                }
                else {
                    st.push(s.charAt(i));
                }
            }
            else{
                st.push(s.charAt(i));
            }
        }
        if(!st.empty())return false;
        return true;
    }
}
