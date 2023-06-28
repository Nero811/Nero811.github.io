#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
    	int len=s.length();
    	int left=0;
    	while(len>=0){  		
	        if(len<k){
	        	cout << "step 1" << endl;
	        	for(int i=left,j=s.length()-1;i<(left+s.length())/2;i++,j--){
	        		swap(s[i],s[j]);
				}
			}
			else if(k<=len && len<k*2){
				cout << "step 2" << endl;
		    	for(int i=left,j=left+k-1;i<left+k/2;i++,j--){
		        		swap(s[i],s[j]);
				}
			}	
			else{
				cout << "step 3" << endl;	
		    	for(int i=left,j=left+k-1;i<left+k/2;i++,j--){
		        		swap(s[i],s[j]);
				}																						
			}
			len-=k*2;	
			left+=k*2;
		}
		cout << s << endl;
		return s;
    }
};
int main(){
	string s;
	Solution sol;
	int k;
	cin >> s;
	cin >> k;
	sol.reverseStr(s,k);
	return 0;
}



