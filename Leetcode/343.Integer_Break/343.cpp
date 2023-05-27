/* ************************************************************************
> File Name:     343.cpp
> Author:        Jack Yang
> Created Time:  2023年05月14日 (週日) 22時51分02秒
> Description:   Integer Break
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
        vector<int>dp(n+1,1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=max(dp[i],max((i-j)*j,dp[i-j]*j));
            }
            cout << dp[i] << " ";
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    int n=10;
    int result=sol.integerBreak(n);
    cout << result;
    return 0;
}
