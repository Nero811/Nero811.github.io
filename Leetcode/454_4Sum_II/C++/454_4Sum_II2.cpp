#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    	int count=0;
		unordered_map<int,int> m;
		for(auto a:nums1){
			for(auto b:nums2){
				m[(a+b)]++;
			}
		}
		
		for(auto c:nums3){
			for(auto d:nums4){
				if(m.find(0-(c+d))!=m.end()){
					count+=m[0-(c+d)];
				}
			}
		}
		cout << "count: " << count << endl;
		return count;
    }
};

int main(){
	Solution sol;
	vector<int> nums1,nums2,nums3,nums4;
	int op1,op2,op3,op4;
	while(op1!=-5){
		cin >> op1;
		if(op1!=-5){
			nums1.push_back(op1);
		}
	}	
	while(op2!=-5){
		cin >> op2;
		if(op2!=-5){
			nums2.push_back(op2);
		}
	}		
	while(op3!=-5){
		cin >> op3;
		if(op3!=-5){
			nums3.push_back(op3);
		}
	}		
	while(op4!=-5){
		cin >> op4;
		if(op4!=-5){
			nums4.push_back(op4);
		}
	}		
	sol.fourSumCount(nums1,nums2,nums3,nums4);
	return 0;
}
