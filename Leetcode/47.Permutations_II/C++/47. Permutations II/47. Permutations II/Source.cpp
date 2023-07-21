#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	void backtracking(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, vector<int>& used) {
		if (path.size() == nums.size()) {
			result.push_back(path);
			return;
		}
		unordered_set<int>st;
		for (int i = 0; i < nums.size(); i++) {
			if (used[i] == true || st.find(nums[i]) != st.end()) {
				continue;
			}
			used[i] = true;
			st.insert(nums[i]);
			path.push_back(nums[i]);
			backtracking(result, path, nums, used);
			used[i] = false;
			path.pop_back();
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> path;
		vector<int>used(nums.size(), false);
		backtracking(result, path, nums, used);
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
	result = sol.permuteUnique(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}