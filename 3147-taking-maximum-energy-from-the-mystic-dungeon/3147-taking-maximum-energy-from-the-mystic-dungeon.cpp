class Solution {
public:
    int dfs(int i, vector<int> &energy, int k, vector<int> &dp){
        if(i < 0) return 0;

        if(dp[i] != -1e9) return dp[i];
        return dp[i] = energy[i] + dfs(i-k,energy,k,dp);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(energy.size(), -1e9);
        int ans = INT_MIN;
        for(int i = 0; i < energy.size(); i++){
            ans = max(energy[i], dfs(i,energy,k,dp));
        }
        return ans;
    }
};