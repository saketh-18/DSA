class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;

        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int left = 0, top = 0;
        if(i-1 >= 0 && i - 1 < grid.size()){
            if(grid[i-1][j] == 0){
                top = dfs(i-1,j,grid,dp);
            }   
        }

        if(j-1 >= 0 && j-1 < grid[0].size()){
            if(grid[i][j-1] == 0){
                left = dfs(i,j-1,grid,dp);
            }
        }

        return dp[i][j] = top+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
       if (obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return dfs(obstacleGrid.size()-1, obstacleGrid[0].size()-1, obstacleGrid, dp);
    }
};