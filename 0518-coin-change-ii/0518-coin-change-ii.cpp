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
        vector<vector<long long>> dp(coins.size(), vector<long long>(amount + 1,0));
        //tabulation
        //base case
        int n =  coins.size();
        for(int i = 1; i < amount+1;i++){
            if(i%coins[0] == 0) dp[0][i] = 1;
        }
        for(int i = 0; i < n;i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i < n;i++){
            for(int j = 1; j < amount+1; j++){
                long long not_take = dp[i-1][j];
                long long take = 0;
                if(j >= coins[i]) take = dp[i][j-coins[i]];
                dp[i][j] = take + not_take;
                if(dp[i][j] > INT_MAX) return 0;
            }
        }
        return (int)dp[n-1][amount];
    }
};