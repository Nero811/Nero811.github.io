#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	int len;
    	vector<int> v1;
    	vector<vector<int>> ans;
    	len=nums.size();
        for(int i=0;i<len;i++){
        	for(int k=0;k<len;k++){
        		if(k!=i){
	 	         	v1.clear();
		    //     	cout << "nums[i]: " << nums[i] << endl;
		        	v1.push_back(nums[i]);       		
		    //    	cout << "nums[k]: " << nums[k] << endl;
		         	v1.push_back(nums[k]);
					int sum=nums[i]+nums[k];
			//		cout << "sum: " << sum << endl;
					for(int j=0;j<len;j++){
						auto it=find(nums.begin()+j,nums.end(),0-sum);
						if(it!=nums.end()){
							int index=it-nums.begin();
							if(index!=i&&index!=k){
			//					cout << "0-sum: " << 0-sum << endl;						
								v1.push_back(0-sum);
								break;								
							}
						}
					}
					sort(v1.begin(),v1.end());
					if(v1.size()==3){
						if(!ans.empty()&&find(ans.begin(),ans.end(),v1)==ans.end()){
			//				cout << "ans.push_back(v1)" << endl;
							ans.push_back(v1);
						}
						else if(ans.empty()){				
							ans.push_back(v1);
						}     					
					}  	      			
				}
			}
		}
		for(int i=0;i<ans.size();i++){
			for(int j=0;j<ans[i].size();j++){
				cout << "ans[i][j] " << ans[i][j] << " " ;
			}
			cout << endl;
		}
		return ans;
    }
};

int main(){
	int op1;
	vector<int> nums;
	Solution sol;
	while(op1!=-5){
		cin >> op1;
		if(op1!=-5){
			nums.push_back(op1);
		}
	}		
	sol.threeSum(nums);
	return 0;
}

