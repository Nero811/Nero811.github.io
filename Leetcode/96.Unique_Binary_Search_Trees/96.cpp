/* ************************************************************************
> File Name:     96.cpp
> Author:        Jack Yang
> Created Time:  2023年05月15日 (週一) 22時49分40秒
> Description:   Unique Binary Search Trees 
 ************************************************************************/
#include<iostream>
using namespace std;
class Solution {
public:
	int numTrees(int n) {
        int *dp=(int *)calloc(20,sizeof(int));        
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
int main(){
    Solution sol;
    int n=3;
    int result=sol.numTrees(n);
    cout << result;
    return 0;
}
