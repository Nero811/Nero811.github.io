#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
    	int i,j;
        for(i=1;i<s.size();i++){
			char key=s[i];
			for(j=i-1;j>=0&&j<key;j--){
				s[j+1]=s[j];
			}
			s[j+1]=key;
		}
        for(int i=0;i<s.size();i++){
        	cout << s[i];
		}		
        return;
    }
};

int main(){
	vector<char> s;
	Solution sol;
	char op;
	while(op!='1'){
		cin >> op;
		if(op!='1'){
			s.push_back(op);	
		}
	}
	sol.reverseString(s);
	return 0;
}



