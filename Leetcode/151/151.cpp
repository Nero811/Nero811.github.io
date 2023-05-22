/* ************************************************************************
> File Name:     151.cpp
> Author:        Jack Yang
> Created Time:  2023年05月06日 (週六) 20時43分30秒
> Description:   Reverse Words in a String 
 ************************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec;
        string newString="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                newString+=s[i];
            }
            if((newString!="" && s[i]==' ') || (newString!="" && i==s.size()-1)){
                vec.push_back(newString);
                newString="";
            }
        }
        reverse(vec.begin(),vec.end());
        string result;
        for(int i=0;i<vec.size();i++){
            result+=vec[i];
            if(i!=vec.size()-1){
                result+=" ";
            }
        }
        return result;
    }
};
int main(){
    Solution sol;
    string result;
//    string s="the sky is blue";
//    string s="  hello world  ";
    string s="a good   example";
    result=sol.reverseWords(s);
    cout << result << endl;
    return 0;
}
