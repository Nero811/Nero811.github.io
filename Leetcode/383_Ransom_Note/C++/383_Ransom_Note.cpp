#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
		map<char,int> m;		
		for(int i=0;i<ransomNote.length();i++){
			m[ransomNote[i]]++;
		}
		for(int i=0;i<magazine.length();i++){
			if(m[magazine[i]]>0){
				m[magazine[i]]--;
			}
		}
		for(auto it:ransomNote){
			if(m[it]!=0){
	//			cout << "false" << endl;
				return false;
			}
		}
	//	cout << "true" << endl;
		return true;
    }
};

int main(){
	Solution sol;
	string ransomNote,magazine;
	cin >> ransomNote;
	cin >> magazine;
	sol.canConstruct(ransomNote,magazine);
	return 0;
}
