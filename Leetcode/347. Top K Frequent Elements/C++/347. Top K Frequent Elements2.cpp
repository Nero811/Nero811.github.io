#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	int count=0;
        unordered_map<int,int> mp;
        deque<int> dq;
        vector<int> result;
        vector<int>::iterator it2;
        
        for(auto a:nums){
        	mp[a]++;
		}

		while(count<=k-1){
	  	    for(auto it=mp.begin();it!=mp.end();it++){
	 			cout << "(*it).first (*it).second: " << (*it).first << " " << (*it).second << endl;					  	    	
	   			while(!dq.empty()&&mp[dq.back()]<(*it).second){
	   				dq.pop_back();
				}
		 	//	cout << "dq.push_back((*it).first): " << (*it).first << endl;
		 		dq.push_back((*it).first);						
			}	
			if(find(result.begin(),result.end(),dq.front())==result.end()){
				result.push_back(dq.front());
				count++;
			}
			mp.erase(dq.front());
			dq.pop_front();				
		}
		return result;
    }
};

int main(){
	Solution sol;
	vector<int> nums,result;
	int op,k;
	while(op!=-5){
		cin >> op;
		if(op!=-5){
			nums.push_back(op);
		}
	}
	cin >> k;
	result=sol.topKFrequent(nums,k);
    for(auto a:result){
    	cout << "a: " << a << endl;
	}	
	return 0;
}
