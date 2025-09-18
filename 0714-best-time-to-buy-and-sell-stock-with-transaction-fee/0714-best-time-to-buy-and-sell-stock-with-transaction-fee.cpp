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
        vector<int> dp = {0,0};
        int n = prices.size();
        for(int i = n-1;i >= 0; i--){
            vector<int> cur = {0,0};
            for(int buy = 0; buy <= 1; buy++){
                if(buy == 0){
                    cur[buy] = max(-prices[i] + dp[1-buy] , dp[buy]);
                } else {
                    cur[buy] = max(prices[i] - fee + dp[1-buy] , dp[buy]);
                }
            }
            dp = cur;
        }
        return dp[0];
    }
};