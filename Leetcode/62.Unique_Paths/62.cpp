/* ************************************************************************
> File Name:     62.cpp
> Author:        Jack Yang
> Created Time:  2023年05月12日 (週五) 22時41分44秒
> Description:   Unique Paths 
 ************************************************************************/
#include<iostream>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
        int dp[101][101];
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    Solution sol;
    int m=3;
    int n=2;
    int result=sol.uniquePaths(m,n);
    cout << result;
    return 0;
}
