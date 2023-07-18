#include<bits/stdc++.h>
#include<vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	void backtracking(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int startidx) {
		if (!path.empty() && path.size() > 1) {
			result.push_back(path);
		}	
		if (startidx >= nums.size()) {
			return;
		}
		unordered_set<int> uset;
		for (int i = startidx; i < nums.size(); i++) {
			if (i > 0 && find(uset.begin(),uset.end(),nums[i])!= uset.end()) {
				continue;
			}
			else if (i > 0 && !path.empty() && nums[i]<path.back()) {
				continue;
			}
			uset.insert(nums[i]);
			path.push_back(nums[i]);
			backtracking(result, path, nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> path;
	//	vector<bool>used(nums.size(), false);
		int startidx = 0;
	//	sort(nums.begin(), nums.end());
		backtracking(result, path, nums, startidx);
		return result;
	}
};
int main() {
	vector<vector<int>> result;
	vector<int> nums;
	Solution sol;
	int val = 0;
	while (val != -1) {
		cin >> val;
		if (val != -1) {
			nums.push_back(val);
		}
	}
	result = sol.findSubsequences(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}