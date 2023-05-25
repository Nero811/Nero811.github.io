#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    	map<char,int> m;
    	map<char,int>::iterator it;
    	int count,len;
		count=t.length();
		len=t.length()-1;
        for(int i=0;i<s.length();i++){
        	m[s[i]]++;
		}
		
	/*	for(it=m.begin();it!=m.end();it++){
			cout << (*it).first << " " << (*it).second << endl;
		}*/
		for(int i=0;i<t.length();i++){
			m[t[i]]--;
		}
		
        for(it=m.begin();it!=m.end();it++){
        	if((*it).second!=0){
        		return false;
			}
		}
		return true;
	}
};

int main(){
	bool isAnagram;
	Solution sol;
	string s,t;
	cin >> s;
	cin >> t;
	
	isAnagram=sol.isAnagram(s,t);
	if(isAnagram){
		cout << "true"<<endl;
	}
	else{
		cout << "false"<<endl;
	}
	return 0;
} 
