#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <deque>
using namespace std;

class Solution {
public:
	bool cmp(pair<int,int>& a, pair<int,int>& b){
		return a.second > b.second;
	}
	
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	int tmp;
        map<int,int> mp;
        deque<int> dq;
        vector<int> result;
        
        for(auto a:nums){
        	mp[a]++;
		}
		

  	    for(auto it=mp.begin();it!=mp.end();it++){
 			cout << "(*it).first (*it).second: " << (*it).first << " " << (*it).second << endl;	 	    	
        	if(it!=mp.begin()&&mp[dq.front()]<=(*it).second){
        		dq.push_front((*it).first);
			}
		/*	else if(it!=mp.begin()&&mp[dq.front()]==(*it).second){
				tmp=dq.front();
				dq.pop_front();
				dq.push_front((*it).first);
				dq.push_front(tmp);
			}*/
			else{
				dq.push_back((*it).first);
			}
		}
		
		for(int i=0;i<k;i++){
			result.push_back(dq.front());
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
