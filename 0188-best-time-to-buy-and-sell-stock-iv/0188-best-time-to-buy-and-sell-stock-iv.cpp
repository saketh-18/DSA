class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                for (int buy = 0; buy <= 1; buy++) {
                    if (buy == 0) {
                        dp[i][j][buy] = max(-prices[i] + dp[i + 1][j][1 - buy],
                                            dp[i + 1][j][buy]);
                    } else {
                        dp[i][j][buy] =
                            max(prices[i] + dp[i + 1][j - 1][1 - buy],
                                dp[i + 1][j][buy]);
                    }
                }
            }
        }
        return dp[0][k][0];
    }
};