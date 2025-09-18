class Solution {
public:
    int rec(int i, vector<int> &prices, int &fee, int buy, vector<vector<int>> &dp){
        if(i == prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy == 0){
            return dp[i][buy] =  max(-prices[i] + rec(i+1,prices,fee,1-buy,dp), rec(i+1,prices,fee,buy,dp));
        } 

        return dp[i][buy] = max(prices[i] - fee + rec(i+1,prices,fee,1-buy,dp) , rec(i+1,prices,fee,buy,dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        int n = prices.size();
        for(int i = n-1;i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy == 0){
                    dp[i][buy] = max(-prices[i] + dp[i+1][1-buy] , dp[i+1][buy]);
                } else {
                    dp[i][buy] = max(prices[i] - fee + dp[i+1][1-buy] , dp[i+1][buy]);
                }
            }
        }
        return dp[0][0];
    }
};