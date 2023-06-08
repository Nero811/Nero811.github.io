#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int FastIdx,SlowIdx;
        set<int> ans;
        set<int>::iterator it;
        for(int i=0;i<haystack.size();i++){
        	if(haystack[i]==needle[0]){
        		int match=0;
        		FastIdx=i;
    			if((i+needle.size())>haystack.size()){
    				break;
				}        		
        		for(int j=0;j<needle.size();j++){
        			if(needle[j]==haystack[FastIdx]){
        				FastIdx++;
        				match++;
					}
					else{
						FastIdx-=2;
						break;
					}
				}
				if(match==needle.size()){
					SlowIdx=i;
					i=FastIdx;
					ans.insert(SlowIdx);
				}
		//			cout << "i: " << i << endl;
			}
		}
		if(ans.empty()){
			cout << "return -1" << endl;
			return -1;
		}
		else{
			it=ans.begin();
			cout << "*it: " << *it << endl;
			return *it;
		}
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

