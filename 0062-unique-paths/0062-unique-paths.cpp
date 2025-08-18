class Solution {
public:
    int dfs(int i , int j, int m , int n , vector<vector<int>> &dp){
        if(i == m-1 && j == n-1) {
            return dp[i][j] = 1;
        } 
        //we need to go down and right
        if(dp[i][j] != -1) return dp[i][j];
        if(i == m-1){
            //we can only go right
            return dp[i][j] = dfs(i,j+1,m,n,dp);
        } else if(j == n-1){
            // we can only go down
            return dp[i][j] = dfs(i+1,j,m,n,dp);
        } 
        return dp[i][j] = dfs(i+1,j,m,n,dp) + dfs(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        int moves = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        // dfs(0,0,m,n,dp);
        dp[m-1][n-1] = 1;
        for(int i = m-1; i >= 0 ; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1) continue;
                int ways = 0;
                if(i+1 < m) ways += dp[i+1][j];
                if(j+1 < n) ways += dp[i][j+1];
                dp[i][j] = ways;
            }
        }
        
        return dp[0][0];
    }
};