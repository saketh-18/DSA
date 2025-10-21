class Solution {
public:
    int minimumTotal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.size();
        vector<int> dp(1,0);
        //tabulation
        dp[0] = grid[0][0];
        for(int i = 1; i < m; i++){
            vector<int> cur(i+1);
            dp.resize(i+1);
            for(int j = 0; j <= i; j++){
                int up = 1e9;
                if(j < i){
                    up = grid[i][j] + dp[j];
                }
                int right = 1e9;
                if(j >= 1){
                    right = grid[i][j] + dp[j-1];
                }

                cur[j] = min(up,right);
            }
            dp = cur;
        }
        int ans = 1e9;

        for(int i : dp){
            ans = min(ans,i);
        }

        return ans;
    }
};