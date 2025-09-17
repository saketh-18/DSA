class Solution {
public:
    int rec(int i, vector<int> &prices, int cnt, bool buy, vector<vector<vector<int>>> &dp){
        if(i == prices.size()) return 0;
        if(cnt == 0) return 0;

        if(dp[i][cnt][buy] != -1) return dp[i][cnt][buy];

        if(buy){
            return dp[i][cnt][buy] = max(
                -prices[i] + rec(i+1, prices, cnt, false, dp),
                 rec(i+1, prices, cnt, true, dp)
            );
        } else {
            return dp[i][cnt][buy] = max(
                prices[i] + rec(i+1, prices, cnt-1, true, dp),
                rec(i+1, prices, cnt, false, dp)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2; // max 2 transactions
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return rec(0, prices, k, true, dp);
    }
};
