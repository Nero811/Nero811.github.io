#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
	bool isPalindrome(string &s,int startidx,int i) {
		for (int j = startidx, k = i ; j < k; j++,k--) {
			if (s[j] != s[k]) {
				return false;
			}
		}
		return true;
	}
	void backtracking(vector<vector<string>> &result, vector<string>& path, string s, int startidx) {
		if (startidx>=s.size()) {
			result.push_back(path);
			return;
		}
		for (int i = startidx; i < s.size() ; i++) {
			if (isPalindrome(s, startidx, i)) {
				string s2 = s.substr(startidx, i - startidx + 1);
				path.push_back(s2);
			}
			else {
				continue;
			}
			backtracking(result, path, s,i+1);
			path.pop_back();
		}
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> path;
		int startidx = 0;
		backtracking(result, path, s, startidx);
		return result;
	}
};
int main() {
	vector<vector<string>> result;
	string s;
	Solution sol;
	cin >> s;
	result = sol.partition(s);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}