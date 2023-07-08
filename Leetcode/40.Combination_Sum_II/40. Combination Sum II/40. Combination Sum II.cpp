#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
	void backtracking(vector<vector<int>>& result, vector<int>& path, vector<int>& candidates, int target, int sum,int startidx) {
		if (sum > target) {
			return;
		}
		if (sum == target) {
				if (find(result.begin(), result.end(), path) == result.end()) {
			result.push_back(path);
				}
			return;
		}
		for (int i = startidx; i < candidates.size() && sum + candidates[i] <= target; i++) {
			cout << "sum: , startidx: " << sum << " ," << startidx << endl;
			if (startidx != i && candidates[startidx] == candidates[i]) {
				continue;
			}
			path.push_back(candidates[i]);
			sum += candidates[i];
			backtracking(result, path, candidates, target, sum, i+1);
			path.pop_back();
			sum -= candidates[i];
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>>result;
		vector<int>path;
		int sum = 0;
		int startidx = 0;
		sort(candidates.begin(), candidates.end());
		backtracking(result, path, candidates, target, sum, startidx);
		return result;
	}
};
int main() {
	vector<vector<int>> result;
	vector<int>candidates;
	Solution sol;
	int val=0;
	while (val != -1) {
		cin >> val;
		if (val != -1) {
			candidates.push_back(val);
		}
	}
	int target;
	cin >> target;
	result = sol.combinationSum2(candidates, target);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
