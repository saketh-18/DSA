class Solution {
public:
    int dfs(int i, vector<int> &nums,vector<int> &dp){
        if(i == 0){
            return dp[0] = nums[i];
        }
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i]+dfs(i-2,nums,dp),dfs(i-1,nums,dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return dfs(nums.size()-1,nums,dp);
    }
};