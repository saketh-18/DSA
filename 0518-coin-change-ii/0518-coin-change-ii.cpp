class Solution {
public:
    int dfs(int i, int amt, vector<int> &coins, vector<vector<int>> &dp){
        if(amt == 0) return 1;
        if(amt < 0) return 0;
        if(i == 0){
            if(amt%coins[i] == 0) return 1;
            return 0;
        }

        if(dp[i][amt] != -1) return dp[i][amt];
        return dp[i][amt] = dfs(i-1,amt,coins,dp) + dfs(i,amt-coins[i], coins,dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1,-1));
        return dfs(coins.size()-1,amount,coins,dp);
    }
};