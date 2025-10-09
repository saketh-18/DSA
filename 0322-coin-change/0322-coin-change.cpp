class Solution {
public:
    int dfs(int i, vector<int> &coins, int amt, vector<vector<int>> &dp){
        if(amt == 0) return 0;
        if(i == coins.size() - 1){
            if(amt%coins[i] == 0){
                return amt/coins[i];
            }
            return 1e9;
        }

        if(dp[i][amt] != -1) return dp[i][amt];
        int not_take = dfs(i+1,coins,amt,dp);
        int take = 1e9;

        if(amt > coins[i]){
            take = 1 + dfs(i,coins,amt-coins[i],dp);
        }

        return dp[i][amt] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1 , -1));
        int ans = dfs(0,coins,amount,dp);

        if(ans == 1e9) return -1;
        return ans;
    }
};