#include <bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target) {
        vector<int>::iterator it;
        bool not_found=true;
        int size = nums.size();
        int mid=size/2;
        for(int i=0;i<mid;i++){
        	if(nums[i]==target){
        		not_found=false;
        		cout << "find " << target << " index: " << i<<endl;
        		return i;       		
			} 
		}
		for(int i=mid;i<size;i++){
        	if(nums[i]==target){
        		not_found=false;
        		cout << "find " << target << " index: " << i<<endl;
        		return i; 
			} 			
		}
		if(not_found){
			cout << "not found!!" << endl; 
			return -1;
		}
    }
    
};

int main(){
	vector<int> nums;
	Solution sol;
	int n;
	while(n != -2){
		cin >> n;
		nums.push_back(n);
	}
	cin >> n;
	sol.search(nums,n);
	
}
