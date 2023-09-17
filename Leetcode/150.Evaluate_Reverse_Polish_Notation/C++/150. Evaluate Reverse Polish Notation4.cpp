#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int sum;
        int slowidx=0;
        int fastidx=0;
        string str;
        bool first_round=true;
        if(tokens.size()==1){       	
        	cout << "tokens[0]: " << tokens[0] << endl;
        	int ans=atoi(tokens[0].c_str());
        	return ans;
		}
        while(fastidx<=tokens.size()-1){    
		//	cout << "fastidx: " << fastidx << endl;    			
	        for(int i=fastidx;i<tokens.size();i++){
	        	if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/"){
	    //  		cout << "tokens[i]: " << tokens[i] << endl;
	    //    		cout << "i: " << i << endl;
	        		st.push(atoi(tokens[fastidx].c_str()));
				}
				else{
					slowidx=i;
					fastidx++; 
					break;
				}
				fastidx++;
			}
			int num1,num2;
			if(st.size()>=2){
				num1=st.top();
				st.pop();
				num2=st.top();
				st.pop();
				if(tokens[slowidx]=="+"){
					sum=(num2+num1);
				}
				else if(tokens[slowidx]=="-"){
					sum=(num2-num1);
				}
				if(tokens[slowidx]=="*"){
					sum=(num2*num1);
				}
				if(tokens[slowidx]=="/"){
					sum=(num2/num1);
				}	
				cout << "sum: " << sum << endl;
				st.push(sum);
			}
		}
		cout << "sum: " << sum << endl;
		return sum;
    }
};

int main(){
	Solution sol;
	vector<string> tokens;
	string op;
	while(op!="-1"){
		cin >> op;
		if(op!="-1"){
			tokens.push_back(op);
		}
	}
	sol.evalRPN(tokens);
	return 0;
}

