#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
		int j=0;
		int max=0;
		int next[s.size()];
		string new_word;
		next[0]=j;
		if(s.size()==1){
			return false;
		}	
		for(int i=1;i<s.size();i++){
			while(j>0&&s[i]!=s[j]){
				j=next[j-1];
			}
			if(s[i]==s[j]){
				j++;
			}
			next[i]=j;
			if(max<j){
				max=j;
			}
		}
		int count=0;
		for(auto a:next){
			cout << a << endl;
		}
		int new_word_len=s.size()-max;
		for(int i=0;i<new_word_len;i++){
			new_word+=s[i];
		}
		cout << "new_word: " << new_word << endl;
		for(int i=0;i<s.size()/new_word_len;i++){
			new_word+=new_word;
		}
/*		while(new_word_len<s.size()){
			new_word_len+=new_word_len;
			new_word+=new_word;
		}*/
		cout << "new_word: " << new_word << endl;
		if(new_word==s){
			cout << "true";
			return true;
		}
		else{
			cout << "false";
			return false;
		}
    }
};

int main(){
	string s;
	Solution sol;
	cin >> s;
	sol.repeatedSubstringPattern(s);
	return 0;
}

