#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m1;
        map<int,int>::iterator it;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
        	if(m1[nums1[i]]==0){
        		cout << "nums1[i] " << nums1[i] << endl;
        		m1[nums1[i]]++;
			}
		}
		
		for(int i=0;i<nums2.size();i++){
			if(m1[nums2[i]]==1){
				m1[nums2[i]]=2;
			}
		}
		
		for(it=m1.begin();it!=m1.end();it++){		
			if((*it).second==2){
		//		cout << "(*it).first " << (*it).first << endl;
				ans.push_back((*it).first);
			}
		}
		return ans;
    }
};


int main(){
	Solution sol;
	vector<int> nums1,nums2;
	int op1,op2;
	
	while(op1!=-1){
		cin >> op1;
		if(op1!=-1){
			nums1.push_back(op1);
		}
	}
	
	while(op2!=-1){
		cin >> op2;
		if(op2!=-1){
			nums2.push_back(op2);
		}
	}
		
	sol.intersection(nums1,nums2);
	return 0;
}
