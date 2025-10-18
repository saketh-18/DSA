class Solution {
public:
    int dfs(int i, int j){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        return dfs(i-1,j) + dfs(i,j-1);
    }
    int uniquePaths(int m, int n) {   
        //tabulation

        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                int top = 0;
                if(i >= 1) top = dp[i-1][j];
                int left = 0;
                if(j >= 1) left = dp[i][j-1];

                dp[i][j] = left + top;
            }
        } 
        return dp[m-1][n-1];    
    }
};