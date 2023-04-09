#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ans;
	unordered_map<int,int>m;
//	map<int,int>m;
	int a=nums.size();
		for(int i=0;i<a;i++){
			m[i]=nums[i];
		}
//		for (const auto& M : m ){
//			cout << M.first << " " << M.second << endl;
//		}
		for(int i=0;i<a;i++){
			for(int j=(a-1);j>i;j--){
				if((target-nums[i])==m[j]){
					ans.push_back(i);
					ans.push_back(j);
					return ans;
				}
			}		
		}
		return ans;
	}
};
	

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Solution S1;
	vector<int> nums;
	vector<int> nums2;
	int target;
	int Nums;
	
	for(int i=0;i<3;i++){
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
