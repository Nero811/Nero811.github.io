#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
	void backtracking(vector<vector<int>> &result,vector<int> &vec,int level,int sum,int k, int n){
		if(vec.size()==k){
			if(sum==n){
				result.push_back(vec);
			}
			return;
		}
	//	cout << "sum: " << sum << endl;
		for(int i=level;i<=9;i++){
			vec.push_back(i);
			backtracking(result,vec,i+1,sum+i,k,n);
			vec.pop_back();
		}	
	}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int>vec;
        int sum=0;
        int level=1;
        backtracking(result,vec,level,sum,k,n);
        return result;
    }
};

int main(){
	vector<vector<int>> result;
	Solution sol;
	int n,k;
	cin >> k;
	cin >> n;
	result=sol.combinationSum3(k,n);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
} 
