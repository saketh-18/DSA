class Solution {
public:
    int rec(int i, int j, vector<int> &prices, vector<vector<int>> &dp){
        if(j >= prices.size()){
            i++;
            if(i < prices.size()-1){
                j = i + 1;
            } else return 0;
        }

        if(i >= prices.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int left = prices[j] - prices[i];
        if(left > 0){
            return dp[i][j] =  max(left + rec(j+2,j+3,prices,dp) ,rec(i,j+1,prices,dp));
        } else {
            return dp[i][j] = rec(i,j+1,prices,dp);
        }

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(prices.size(), -1));
        return rec(0,1,prices, dp);
    }
};