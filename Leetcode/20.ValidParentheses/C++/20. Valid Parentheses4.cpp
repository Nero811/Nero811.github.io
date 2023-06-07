#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sk1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				sk1.push(')');
			}
			else if(s[i]=='['){
				sk1.push(']');
			}
			else if(s[i]=='{'){
				sk1.push('}');
			}			
			

			if(s[i]==')'){
				if(!sk1.empty()){
					if(sk1.top()==')'){
						sk1.pop();
					}
					else{
						return false;
					}					
				}
				else{
					return false;
				}
			}
			else if(s[i]==']'){
				if(!sk1.empty()){
					if(sk1.top()==']'){
						sk1.pop();
					}
					else{
						return false;
					}					
				}
				else{
					return false;
				}				
			}
			else if(s[i]=='}'){
				if(!sk1.empty()){
					if(sk1.top()=='}'){
						sk1.pop();
					}
					else{
						return false;
					}					
				}
				else{
					return false;
				}			
			}											
		}
		if(!sk1.empty()){
			return false;
		}
		cout << "true" << endl;
 		return true;
 	}
};


int main(){
	string s;
	Solution sol;
	cin >> s;
	sol.isValid(s);
	return 0;
}
