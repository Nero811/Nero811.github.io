#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    	multimap<char,int> m;
    	multimap<char,int>::iterator it;
    	int count,len;
		count=t.length();
		len=t.length()-1;
        for(int i=0;i<s.length();i++){
        	m.insert(pair<char,int>(s[i],1));
		}
		
	/*	for(it=m.begin();it!=m.end();it++){
			cout << (*it).first << " " << (*it).second << endl;
		}*/
		if(s.length()!=t.length()){
			return false;
		}
		else{
			while(len>=0){
				for(it=m.begin();it!=m.end();it++){
					if((*it).first==t[len]&&(*it).second==1){
		//				cout << "t[len]: " << t[len] << endl;
						(*it).second--;
						m.erase(it);
		//				cout << (*it).first << " " << (*it).second << endl;					
						count--;
						break;
					}
				}
				len--;
			}
		//	cout << "count: " << count << endl;
		//	cout << "s.length(): " << s.length() << endl;
			if(count==0){
				return true;
			}
			else{
				return false;
			}
   		}	
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
