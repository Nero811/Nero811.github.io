#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size=nums.size();
        for(int i=0;i<size;i++){
        	nums[i]*=nums[i];
		}
		sort(nums.begin(),nums.end());
		for(int i=0;i<size;i++){
			cout << nums[i] << " ";
		}
		return nums;
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
	sol.sortedSquares(nums);		
}
