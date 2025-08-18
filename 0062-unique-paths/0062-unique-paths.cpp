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
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dfs(0,0,m,n,dp);
        return dp[0][0];
    }
};