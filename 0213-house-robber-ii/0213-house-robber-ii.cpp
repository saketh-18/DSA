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
        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];

        //without last element
        int take = 0;
        int not_take = 0;
        for(int i = 1; i < nums.size() - 1; i++){
            take = nums[i];
            if(i > 1) take += dp[i-2];
            not_take = dp[i-1];
            dp[i] = max(not_take,take);
        }

        int ans1 = dp[nums.size() - 2];
        //without first element
        fill(dp.begin(),dp.end(),0);
        dp[1] = nums[1];
        for(int i = 2; i < nums.size(); i++){
            take = nums[i];
            if(i > 2) take += dp[i-2];
            not_take = dp[i-1];

            dp[i] = max(take,not_take);
        }

        int ans2 = dp[nums.size() - 1];

        return max(ans2, ans1);
    }
};