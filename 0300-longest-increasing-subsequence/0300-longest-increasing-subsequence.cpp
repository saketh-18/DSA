class Solution {
public:
    int dfs(int i, vector<int> &nums, int last, vector<vector<int>> &dp){
        if(i >= nums.size()) return 0;

        if(last != -1 && dp[i][last] != -1) return dp[i][last];
        int take = 0;
        if(last == -1 || nums[i] > nums[last]){
            take = 1 + dfs(i + 1, nums, i, dp);
        }
        int not_take = dfs(i+1,nums,last, dp);
        if(last != -1) return dp[i][last] = max(take,not_take);
        return max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return dfs(0,nums,-1, dp);
    }
};