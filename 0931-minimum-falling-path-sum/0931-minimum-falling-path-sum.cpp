class Solution {
public:
    int dfs(int i , int j , vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(i == matrix.size() - 1) return dp[i][j] = matrix[i][j];
        
        if(dp[i][j] != INT_MAX) return dp[i][j];
        if(j == matrix.size() - 1){
            return dp[i][j] = min(matrix[i][j] + dfs(i+1,j,matrix,dp) , matrix[i][j] + dfs(i+1,j-1,matrix,dp));
        }
        if(j == 0){
            return dp[i][j] = min(matrix[i][j] + dfs(i+1,j,matrix,dp) , matrix[i][j] + dfs(i+1,j+1,matrix,dp));
        }
        return dp[i][j] = min(matrix[i][j] + dfs(i+1,j,matrix,dp) , min(matrix[i][j]+dfs(i+1,j+1,matrix,dp) , matrix[i][j] + dfs(i+1,j-1,matrix,dp)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //should apply recursion to all the elements in first row
        int minsu = INT_MAX;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(),INT_MAX));
        for(int i = 0 ; i < matrix.size(); i++){
            minsu = min(minsu, dfs(0,i,matrix,dp));
        }
        return minsu;
    }
};