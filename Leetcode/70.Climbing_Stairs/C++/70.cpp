/* ************************************************************************
> File Name:     70.cpp
> Author:        Jack Yang
> Created Time:  2023年05月11日 (週四) 21時44分13秒
> Description:   Climbing Stairs 
 ************************************************************************/
#include<iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
        int dp[46]={0};
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    int result;
    result=sol.climbStairs(3);
    cout << result << endl;
    return 0;
}
