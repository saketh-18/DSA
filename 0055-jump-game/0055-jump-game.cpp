class Solution {
public:
    bool dfs(int i, vector<int> &nums, vector<int> &dp){
        if(i >= nums.size() - 1) return true;

        if(nums[i] == 0) return false;

        if(dp[i] != -1) return dp[i];
        for(int j = i + 1; j <= i + nums[i]; j++){
            if(dfs(j,nums,dp)) return dp[j] =  true;
        } 
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        return dfs(0,nums,dp);
    }
};