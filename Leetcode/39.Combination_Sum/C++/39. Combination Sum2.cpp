#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
private:
public:		
	void backtracking(vector<vector<int>>& result, vector<int>& path,vector<int>& candidates, int target,int sum,int startidx) {
		if (sum >=target) {
			if (sum==target) {
				if(find(result.begin(),result.end(),path)==result.end()){
					result.push_back(path);
				}
			}
			return;
		}
		for (int i = startidx;i < candidates.size();i++) {
			path.push_back(candidates[i]);
			sum += candidates[i];
			backtracking(result,path,candidates,target,sum,i);
			path.pop_back();
			sum -= candidates[i];
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>>result;
		vector<int>path;
		int sum=0;
		backtracking(result, path, candidates, target, sum,0);
		cout << result.size() << endl;
		return result;
	}
};
int main() {
	vector<vector<int>> result;
	vector<int>candidates;
	Solution sol;
	int val;
	while (val!=-1) {
		cin >> val;
		if (val!=-1) {
			candidates.push_back(val);
		}
	}
	int target;
	cin >> target;
	result = sol.combinationSum(candidates, target);
	for (int i = 0;i < result.size();i++) {
		for (int j = 0;j < result[i].size();j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
