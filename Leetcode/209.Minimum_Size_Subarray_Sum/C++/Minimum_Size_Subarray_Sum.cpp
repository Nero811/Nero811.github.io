#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int max,length,slowidx=0,sum=0;    
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
        	cout << "nums[i] :" << nums[i] << endl;
        	sum+=nums[i];	        	
        	cout << "sum: " << sum << endl;
        	if(sum>=target){
        		nums[slowidx++]=nums[i];
 				cout << "slowidx :" << slowidx <<endl;
				cout << "nums[slowidx] : " << nums[slowidx] << endl;
        		cout << "slowidx+1 " << slowidx+1 << endl;
        		return slowidx+1;	
			}
			else{
 				nums[slowidx++]=nums[i];
				cout << "slowidx :" << slowidx <<endl;
				cout << "nums[slowidx] : " << nums[slowidx] << endl;				
			}
		//	slowidx++;
		}  			 	
		return 0;		
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
