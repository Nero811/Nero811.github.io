/* ************************************************************************
> File Name:     1002.cpp
> Author:        Jack Yang
> Created Time:  2023/04/22
> Description:   
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        if(words.size()==1)return words;
        vector<int> dic(26,0);
        for(int i=0;i<words[0].size();i++){
            dic[words[0][i]-'a']++;
        }
        vector<int> pre(dic.begin(),dic.end());
        vector<int> cur(26,0);
        vector<int> temp;
        for(int i=1;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(pre[words[i][j]-'a']>0){
                    pre[words[i][j]-'a']--;
                    cur[words[i][j]-'a']++;
                }
            }
            if(i==words.size()-1){
                for(int &a:cur){
                    temp.push_back(a);
                }
                break;
            }
            for(int k=0;k<26;k++){
                pre[k]=cur[k];
            }
            for(int k=0;k<26;k++){
                cur[k]=0;
            }
        }
        vector<string>result;
        for(int i=0;i<27;i++){
            while(temp[i]>0){
                temp[i]--;
                int num=(i+97);
                char ch=char(num);
                string st="";
                st+=ch;
                result.push_back(st);
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
   // vector<string> words={"bella","label","roller"};
    vector<string> words={"cool","lock","cook"};
    vector<string>result;
    result=sol.commonChars(words);
    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    return 0;
}
