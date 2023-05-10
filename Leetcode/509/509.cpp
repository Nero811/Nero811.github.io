/* ************************************************************************
> File Name:     509.cpp
> Author:        Jack Yang
> Created Time:  2023年05月10日 (週三) 21時59分24秒
> Description:   Fibonacci Number 
 ************************************************************************/
#include<iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int dp[31]={0};
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
int main(){
    Solution sol;
    int n=4;
    int result=sol.fib(n);
    cout << result ;
    return 0;
}
