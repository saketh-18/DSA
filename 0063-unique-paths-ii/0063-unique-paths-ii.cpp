class Solution {
public:
    int dfs(int i , int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
      if(i == 0 && j == 0) return dp[0][0] = 1;
      if(i < 0 || j < 0) return 0;

      //should go top and left;
      //only call dfs if there is no obstacle

      int top = 0 , left = 0;
      if(dp[i][j] != -1) return dp[i][j];
      if(i > 0 && grid[i-1][j] != 1){
        top = dfs(i-1,j,grid,dp);
      }
      if(j > 0 && grid[i][j-1] != 1){
        left = dfs(i,j-1,grid,dp);
      }
      return dp[i][j] = top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        //use recursion();
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        if(grid[m][n] == 1) return 0;
        if(grid[0][0] == 1) return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //tabulation approach => 
        dp[0][0] = 1;
        for(int i = 0 ; i <= m; i++){
          for(int j = 0 ; j <= n; j++){
            if(i == 0 && j == 0) continue;
            if(grid[i][j] == 1) continue;

            if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];

          }
        }
        return dp[m][n];
    }
};