#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
	void backtracking(vector<vector<int>> &result, vector<int> &path, vector<int>& nums,int startidx) {
		if (startidx >= nums.size()) {
		//	if (find(result.begin()+1,result.end(),path)== result.end()) {
				result.push_back(path);
		//	}
			return;
		}
		for (int i = startidx; i < nums.size();i++) {
			path.push_back(nums[i]);
			backtracking(result, path, nums,i+1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int>newNums;
		vector<int> path;
		int startidx=0;
		result.push_back({});
		sort(nums.begin(),nums.end());
		for (int i = 0; i < nums.size();i++) {
			newNums.push_back(nums[i]);
			backtracking(result, path, newNums, startidx);
		}
		return result;
	}
};
int main() {
	vector<vector<int>> result;
	vector<int> nums;
	Solution sol;
	int val=0;
	while (val != -1) {
		cin >> val;
		if (val!=-1) {
			nums.push_back(val);
		}
	}
	result = sol.subsets(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size();j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}