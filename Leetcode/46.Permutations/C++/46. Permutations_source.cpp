#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	void backtracking(vector<vector<int>>& result, vector<int>& path, vector<int>& nums,  unordered_set<int>&st) {
		if (path.size() == nums.size()) {
			result.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (st.find(nums[i])!=st.end()) {
				continue;
			}
			st.insert(nums[i]);
			path.push_back(nums[i]);
			backtracking(result, path, nums, st);
			st.erase(nums[i]);
			path.pop_back();
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> path;
		unordered_set<int>st;
	//	int startidx = 0;
		sort(nums.begin(), nums.end());
		backtracking(result, path, nums, st);
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
	result = sol.permute(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
