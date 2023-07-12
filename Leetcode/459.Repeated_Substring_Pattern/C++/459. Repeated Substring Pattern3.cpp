#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void GetNext(int *next,string s){
		int j=0;
		next[0]=j;
		for(int i=1;i<s.size();i++){
			while(j>0&&s[i]!=s[j]){
				j=next[j-1];
			}
			if(s[i]==s[j]){
				j++;
			}
			next[i]=j;
		}
	}
    bool repeatedSubstringPattern(string s) {
		int j=0;
		int max=0;
		int next[s.size()];
		GetNext(next,s);
		if(s.size()==1){
			return false;
		}	
		int len=s.size();
		for(auto a:next){
			cout << a << endl; 
		}
		if(next[len-1]!=0&&len%(len-next[len-1])==0){
			cout << "return true";
			return true;
		}
		cout << "return false";
		return false;
    }
};

int main(){
	string s;
	Solution sol;
	cin >> s;
	sol.repeatedSubstringPattern(s);
	return 0;
}

