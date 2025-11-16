class Solution {
public:
    long long dfs(int i, vector<int> &coins, int amt, vector<vector<int>> &dp){
        if(i == 0){
            if(amt%coins[i] == 0){
                return amt/coins[i];
            } 
            return INT_MAX;
        } 

        if(amt == 0) return 0;
        if(amt < 0) return INT_MAX;
        if(dp[i][amt] != -1) return dp[i][amt]; 
        long long take = INT_MAX;
        long long not_take = 0;
        if(amt >= coins[i]){
            take = 1 + dfs(i,coins,amt-coins[i], dp);
        } 

        not_take = dfs(i-1,coins,amt, dp);
        return dp[i][amt] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = dfs(coins.size() - 1, coins, amount, dp);
        if(ans >= INT_MAX) return -1;
        return ans;
    }
};