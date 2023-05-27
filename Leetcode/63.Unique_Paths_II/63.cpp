/* ************************************************************************
> File Name:     63.cpp
> Author:        Jack Yang
> Created Time:  2023年05月13日 (週六) 20時12分48秒
> Description:   Unique Paths II 
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[101][101];
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        bool stackle=false;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1){
                stackle=true;    
            }
            if(!stackle)dp[i][0]=1;
            else dp[i][0]=0;
        }
        stackle=false;
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==1){
                stackle=true;
            }
            if(!stackle)dp[0][i]=1;
            else dp[0][i]=0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    Solution sol;
    vector<vector<int>>obstacleGrid={{0,0,0},{0,1,0},{0,0,0}};
//    vector<vector<int>>obstacleGrid={{0,1},{0,0}};
    int result=sol.uniquePathsWithObstacles(obstacleGrid);
    cout << result;
    return 0;
}
