#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	int count=0;
        unordered_map<int,int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>> ,greater<pair<int, int>>> pq;
        vector<int> result;
        vector<int>::iterator it2;
        
        for(auto a:nums){
        	mp[a]++;
		}
				
  	    for(auto it=mp.begin();it!=mp.end();it++){
 			pq.push({(*it).second,(*it).first});
		}	
		
		while(pq.size()>k){
			pq.pop();
		}
		
		while(!pq.empty()){
			auto now=pq.top();
			result.push_back(now.second);
			pq.pop();
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
