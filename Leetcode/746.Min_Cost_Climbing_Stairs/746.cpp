/* ************************************************************************
> File Name:     746.cpp
> Author:        Jack Yang
> Created Time:  2023年05月11日 (週四) 22時18分16秒
> Description:   Min Cost Climbing Stairs 
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
        int dp[1001]={0};
        dp[0]=cost[0];
        dp[1]=cost[1];
        int size=cost.size();
        for(int i=2;i<=size;i++){
            if(i!=size){
                dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
            }
            else{
                dp[i]=min(dp[i-1],dp[i-2]);
            }
        }
        return dp[size];
    }
};

int main(){
    Solution sol;
    vector<int>cost={1,100,1,1,1,100,1,1,100,1};
    int result=sol.minCostClimbingStairs(cost);
    cout << result;
    return 0;
}
