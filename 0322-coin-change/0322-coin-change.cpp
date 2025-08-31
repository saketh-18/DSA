class Solution {
public:
    int dfs(int i, int k, vector<int> &coins, vector<vector<int>> &dp){
        if(k == 0) return 0;
        if(i == 0){
            if(k%coins[0] == 0) return k/coins[0];
            return 1e9;
        }

        if(dp[i][k] != -1) return dp[i][k];
        int not_take = dfs(i-1,k,coins,dp);
        int take = INT_MAX;
        if(k >= coins[i]) take = 1 + dfs(i,k-coins[i],coins,dp);
        return dp[i][k] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        int ans = dfs(coins.size()-1,amount,coins,dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};