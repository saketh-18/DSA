class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i >= grid.size()){
            return 0;
        }

        if(j >= grid[i].size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int down = grid[i][j] + dfs(i+1,j,grid,dp);
        int right = grid[i][j] + dfs(i+1,j+1,grid,dp);

        return dp[i][j] = min(down,right);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        //tabulation
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            for(int j = 0; j <= i; j++){
                int up = 1e9;
                if(j < i){
                    up = grid[i][j] + dp[i-1][j];
                }
                int right = 1e9;
                if(j >= 1){
                    right = grid[i][j] + dp[i-1][j-1];
                }

                dp[i][j] = min(up,right);
            }
        }
        int ans = 1e9;

        for(int i : dp[m-1]){
            ans = min(ans,i);
        }

        return ans;
    }
};