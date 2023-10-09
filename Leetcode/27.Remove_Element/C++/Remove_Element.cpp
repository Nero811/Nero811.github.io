#include <bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
  		int size=nums.size();
  		int i=0;
  		cout << "size : " << size << endl;
  		for(int i=0;i<size;i++){
  			if(nums[i]==val){
  		//		cout << "i: " << i << endl;
  				nums[i]=-1;
			}
		} 
		while(i!=size){
  			if(nums[i]==-1){
  				cout << "i: " << i << endl;
  				nums.erase(nums.begin()+i);
  				size=nums.size();
  				i=0;
			}	
			else{
				i++;
			}					
		}
		size=nums.size();
		cout << "new size : " << size << endl;
		return size;
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
	sol.removeElement(nums,n);	
	
}
