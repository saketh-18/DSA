class Solution {
public:
    int dfs(int i, int j,vector<vector<int>> &dp){
        if(i == 0 && j == 0) return dp[0][0] = 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = dfs(i-1,j,dp) + dfs(i,j-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1]; 
            }
        }
        return dp[m-1][n-1];
        // return dfs(m-1,n-1,dp);
    }
};