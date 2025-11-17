class Solution {
public:
    int dfs(int i, vector<int> &nums, vector<int> &dp){
        if(i >= nums.size() - 1) return 0;

        if(dp[i] != -1) return dp[i];
        int mini = 1e9;
        for(int j = i + 1; j <= i + nums[i]; j++){
            mini = min(mini, 1 + dfs(j,nums,dp));
        }   
        return dp[i] = mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(0,nums,dp);
    }
};