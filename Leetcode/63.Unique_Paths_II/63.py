from typing import List
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m=len(obstacleGrid)
        n=len(obstacleGrid[0])
        dp=[[0 for j in range(n)]for i in range(m)]
        for i in range(n):
            if obstacleGrid[0][i] == 1:
                break;
            dp[0][i]=1
        for i in range(m):
            if obstacleGrid[i][0] == 1:
                break;
            dp[i][0]=1
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j] == 0:
                    dp[i][j]=dp[i][j-1]+dp[i-1][j]
        return dp[m-1][n-1]

sol=Solution()
obstacleGrid=[[0,0,0],[0,1,0],[0,0,0]]
print(sol.uniquePathsWithObstacles(obstacleGrid))
