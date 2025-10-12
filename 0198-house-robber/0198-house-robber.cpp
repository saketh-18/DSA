class Solution {
public:
    int dfs(int i, vector<int> &nums, vector<int> &dp){
        if(i == 0) return nums[i];

        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];
        int skip = dfs(i-1,nums,dp);
        int take = nums[i] + dfs(i-2,nums,dp);
        return dp[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(nums.size() - 1, nums, dp);
    }
};