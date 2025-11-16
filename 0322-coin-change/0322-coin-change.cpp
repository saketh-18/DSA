class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        vector<long long> dp(amount + 1);
        for(int i = 0; i <= amount; i++){
            if(i%coins[0] == 0){
                dp[i] = i/coins[0];
            } else {
                dp[i] = INT_MAX;
            }
        }
        for(int i = 1; i < coins.size(); i++){
            vector<long long> roll(amount + 1);
            for(int j = 0; j <= amount; j++){
                long long take = INT_MAX;
                if(j >= coins[i]){
                    take = 1 + roll[j-coins[i]];
                }
                long long not_take = dp[j];

                roll[j] = min(take,not_take);
            }
            dp = roll;
        }

        if(dp[amount] >= INT_MAX) return -1;
        return dp[amount];
    }
};