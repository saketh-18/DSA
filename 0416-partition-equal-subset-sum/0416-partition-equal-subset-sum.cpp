class Solution {
public:
    bool dfs(int i, int sum, vector<int>& nums, vector<vector<int>> &dp) {
        if(sum == 0) return true;
        if(i == 0) return sum == 0 || sum == nums[0];
        if(sum < 0) return false;
        if(dp[i][sum ] != -1) return dp[i][sum];
        return dp[i][sum] = dfs(i-1,sum-nums[i],nums,dp) || dfs(i-1,sum,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if(sum%2 != 0) return false;
        //check for sum/2
        vector<vector<int>> dp(n,vector<int>((sum/2)+1 , -1));
        return dfs(n-1,sum/2,nums,dp);
    }
};