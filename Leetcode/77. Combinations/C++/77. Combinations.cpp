#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
	void backtracking(vector<vector<int>> &result,vector<int> &vec,int level,int n, int k){
		if(vec.size()==k){
			result.push_back(vec);
			return;
		}
		for(int i=level;i<=n;i++){
			vec.push_back(i);
			backtracking(result,vec,i+1,n,k);
			vec.pop_back();
		}	
	}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int>vec;
        int level=1;
        backtracking(result,vec,level,n,k);
        return result;
    }
};

int main(){
	vector<vector<int>> result;
	Solution sol;
	int n,k;
	cin >> n;
	cin >> k;
	result=sol.combine(n,k);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
} 
