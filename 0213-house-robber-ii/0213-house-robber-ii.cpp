class Solution {
public:
    int dfs(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0)
            return 0;

        if (i == 0)
            return nums[i];

        if (dp[i] != -1)
            return dp[i];
        int take = nums[i] + dfs(i - 2, nums, dp);
        int not_take = dfs(i - 1, nums, dp);

        return dp[i] = max(take, not_take);
    }

    int dfs1(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 1)
            return 0;

        if (i == 1)
            return nums[i];

        if (dp[i] != -1)
            return dp[i];
        int take = nums[i] + dfs1(i - 2, nums, dp);
        int not_take = dfs1(i - 1, nums, dp);

        return dp[i] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), -1);
        int ans1 = dfs(nums.size() - 2, nums,dp);
        fill(dp.begin(), dp.end() , -1);
        int ans2 = dfs1(nums.size()-1, nums,dp);
        return max(ans1, ans2);
    }
};