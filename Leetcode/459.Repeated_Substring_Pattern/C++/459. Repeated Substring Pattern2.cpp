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
		if(max==0){
			return false;
		}
		int new_word_len=s.size()-max;
		for(int i=0;i<new_word_len;i++){
			new_word+=s[i];
		}
		cout << "new_word: " << new_word << endl;
		cout << "s.size()/new_word_len=" << s.size()/new_word_len << endl;
		string ans;
		for(int i=0;i<s.size()/new_word_len;i++){
			ans+=new_word;
		}
		if(ans==s){
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

