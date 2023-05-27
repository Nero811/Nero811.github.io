#include <bits/stdc++.h>
#include <vector>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> v1;
        for(int i=0;i<s.size();i++){
        	if(v1.empty()){
        		v1.push_back(s[i]);
			}
			else{
	        	if(v1.back()!=s[i]){
	        		v1.push_back(s[i]);
				}
				else{
					v1.pop_back();
				}				
			}
		}
		string ans;
		for(auto a:v1){
			cout << a << endl;
			ans+=a;
		}
		cout << "ans: " << ans << endl;
		return ans;
    }
};

int main(){
	string s;
	Solution sol;
	cin >> s;
	sol.removeDuplicates(s);
	return 0;
}
