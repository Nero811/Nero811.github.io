#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:	

    vector<int> twoSum(vector<int>& nums, int target) {
    		int test=0;
    		vector<int> sol;
    		
    		int len=nums.size();
    		
    			if(target == 0){
    				for(int i=0;i<len;i++){
    					test=target-nums[i];
							for(int j=(i+1);j<len;j++){
									test-=nums[j];									
										if(test==0){
											sol.push_back(i);
					    					sol.push_back(j); 
											return sol;																																							
										}
										else{																
											test=target-nums[i];
										}															

							}
						   					
					}
				}
				else{
					for(int i=0;i<len;i++){
		    			test=target-nums[i];
		    			if(test != 0){
		    					for(int j=(i+1);j<len;j++){
		    						test-=nums[j];
		    						if(test==0){
		    							sol.push_back(i);
		    							sol.push_back(j); 
										return sol;	
									}
									else{
										test=target-nums[i];
									}
								}
						}    															
					}

				}
			
			return sol;	
    }
    
    
};


int main(int argc, char** argv) {
	Solution S1;
	vector<int> nums;
	vector<int> nums2;
	int target;
	int Nums;
	
	for(int i=0;i<5;i++){
		cin >> Nums;
		nums.push_back(Nums);
	}
	cin >> target;
	nums2=S1.twoSum(nums,target);	
	for(int i=0;i<2;i++){
		cout << nums2[i];	
	}
	
	return 0;
}
