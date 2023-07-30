#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    	int sum,ans,count=0,len;
    	set<set<int>> s1;
    	set<int> s2;
  		for(int i=0;i<nums1.size();i++){
  			for(int j=0;j<nums2.size();j++){
  				for(int k=0;k<nums3.size();k++){
  					for(int l=0;l<nums4.size();l++){
  					//	s2.clear();
  						sum=nums1[i]+nums2[j]+nums3[k]+nums4[l];
  						cout << "sum: " << sum << endl;
						if(sum==0){
							count++;
						/*	cout << "found !!" << endl;
							s2.insert(nums1[i]);
							s2.insert(nums2[j]);
							s2.insert(nums3[k]);
							s2.insert(nums4[l]);	
							len=s1.size();
							if(!s1.empty()){
								if(s1.find(s2)==s1.end()){
									cout << "s1.insert(s2)" << endl;
									s1.insert(s2);
								}				
							}
							else{
								s1.insert(s2);
							}	*/		
						}  					
					}
				}
			}
		}
	//	cout << "s1.size()" << s1.size() << endl; 
	//	return s1.size();
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
