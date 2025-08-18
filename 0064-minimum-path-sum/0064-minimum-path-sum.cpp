class Solution {
public:
    int dfs(int i , int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
      if(i == 0 && j == 0){
        return dp[i][j] = grid[i][j];
      }

      if(i < 0 || j < 0) return 201;
      if(dp[i][j] != -1) return dp[i][j];
      int top = INT_MAX, left = INT_MAX;
      if(i > 0){
        top = grid[i][j] + dfs(i-1,j,grid,dp);
      }
      if(j > 0){
        left = grid[i][j] + dfs(i,j-1,grid,dp);
      }
      return dp[i][j] = min(top,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
      vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
      return dfs(grid.size()-1,grid[0].size()-1,grid,dp);
    }
};