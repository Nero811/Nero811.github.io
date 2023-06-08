#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
	void GetNext(int * next,string s){
		int j=0;
		next[0]=0;
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
    int strStr(string haystack, string needle) {
 		int next[needle.size()];
 		this->GetNext(next,needle);
 		int j=0;
 		for(auto a:next){
 			cout << "a: " << a << endl;
		}
 		for(int i=0;i<haystack.size();i++){
 			cout << "haystack[i]: " << haystack[i] << endl;
 			cout << "needle[j]: " << needle[j] << endl;
			while(j>0&&haystack[i]!=needle[j]){
				j=next[j-1];
			}
			if(haystack[i]==needle[j]){
				j++;
			}
			cout << "j: " << j << endl;
			if(j==needle.size()){
				cout << "i-needle.size()+1: " << i-needle.size()+1 << endl;
				return i-needle.size()+1;
			}
		}
		return -1;
    }
};

int main(){
	string haystack,needle;
	Solution sol;
//	getline (cin,haystack);
//	getline (cin,needle);
	cin >> haystack;
	cin >> needle;
//	cout << "s: " << s << endl;
	sol.strStr(haystack,needle);
	return 0;
}

