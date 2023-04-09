#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
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
		s.push_back(op);
	}
	sol.reverseString(s);
	return 0;
}



