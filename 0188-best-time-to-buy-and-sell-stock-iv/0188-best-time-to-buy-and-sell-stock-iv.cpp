class Solution {
public:
    int rec(int i, int k, int buy, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(i == prices.size() || k == 0) return 0;

        if(dp[i][k][buy] != -1) return dp[i][k][buy];
        if(buy == 0){
            return dp[i][k][buy] =  max(-prices[i] + rec(i+1,k,1-buy,prices,dp) , rec(i+1,k,buy,prices,dp));
        }

        return dp[i][k][buy] =  max(prices[i] + rec(i+1,k-1,1-buy,prices,dp) , rec(i+1,k,buy,prices,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k+1, vector<int>(2,-1)));
        return rec(0,k,0,prices,dp);
    }
};