class Solution {
public:
    int dfs(int i , int j ,vector<vector<int>> &triangle, vector<vector<int>> &dp){
        if(i == triangle.size() - 1) return dp[i][j] = triangle[i][j];

        if(dp[i][j] != INT_MAX) return dp[i][j];
        return dp[i][j] = min(triangle[i][j] + dfs(i+1,j,triangle,dp) , triangle[i][j] + dfs(i+1,j+1,triangle,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(),INT_MAX));
        return dfs(0,0,triangle,dp);
    }
};