class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2; // max 2 transactions
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));

        for(int i = n-1; i >= 0; i--){
            for(int cap = 1; cap <= k; cap++){
                for(int buy = 0 ; buy <= 1; buy++){
                    if(buy == 1){
                        dp[i][cap][buy] = max(-prices[i] + dp[i+1][cap][0],
                                               dp[i+1][cap][1]);
                    } else {
                        dp[i][cap][buy] = max(prices[i] + dp[i+1][cap-1][1],
                                               dp[i+1][cap][0]);
                    }
                }
            }
        }
        return dp[0][k][1]; // start at day 0, k transactions, allowed to buy
    }
};
