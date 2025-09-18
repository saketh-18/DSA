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
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return rec(0,prices,fee,0,dp);
    }
};