#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int index=0,result=0,final_result=nums.size(),sum=0;  
		for(int i=0;i<nums.size();i++){
			sum=0;
			index=0;
			for(int j=i;j<nums.size();j++){
				sum+=nums[j];
				if(sum >= target){
					result=index;
					if(result<final_result){
						final_result=result;
					}
					break;
				}
				index++;
			}
		}
		if(final_result==nums.size()){
			return 0;
		}
		else{
			cout << "final_result+1 : " << final_result+1 << endl;
			return final_result+1;					
		}
    }
};

int main(){
	vector<int> nums;	
	Solution sol;
	int n;
	while(n != -2){
		cin >> n;
		if(n != -2){
			nums.push_back(n);	
		}
	}
	cin >> n;
	sol.minSubArrayLen(n,nums);
}