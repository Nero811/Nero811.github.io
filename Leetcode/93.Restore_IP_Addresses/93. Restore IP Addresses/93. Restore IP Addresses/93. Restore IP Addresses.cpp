#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
	bool isVaildIP(string& s, int start, int end) {
		string IP = "";
		if (start>end) {
			return false;
		}
		if (s[start]=='0'&&start!=end) {
			return false;
		}
		int num = 0;
		for (int j = start; j <= end; j++) {
			if (s[j]<'0'||s[j]>'9') {
				return false;
			}
		//	num = num * 10 + (s[j]-'0');
			IP.push_back(s[j]);
			int num = stoi(IP);
			if (num>255) {
				return false;
			}
		}
		return true;
	}
	void backtracking(vector<string>& result, string s, int startidx,int pointNum) {
		if (pointNum == 3) {
			if (isVaildIP(s,startidx,s.size()-1)) {
				result.push_back(s);
			}
			return;
		}
		for (int i = startidx; i < s.size(); i++) {
			if (isVaildIP(s, startidx,i)) {
				s.insert(s.begin() + i + 1, '.');
				cout << "s: " << s << endl;
				pointNum++;
				backtracking(result, s, i + 2, pointNum);
				pointNum--;
				s.erase(s.begin() + i + 1);
			}
			else {
				break;
			}
		}
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		int startidx = 0;
		int pointNum = 0;
		backtracking(result, s, startidx, pointNum);
		return result;
	}
};
int main() {
	vector<string> result;
	string s;
	Solution sol;
	cin >> s;
	result = sol.restoreIpAddresses(s);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}
