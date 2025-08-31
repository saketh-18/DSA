class Solution {
public:
    int dfs(int i, int sum, int &target, vector<int> &nums,  vector<vector<int>> &dp, int &ind){
        if(i >= nums.size()){
            if(target == sum) return 1;
            return 0;
        }
        
        if(dp[i][sum + ind] != -1) return dp[i][sum+ind];
        int plus = dfs(i+1,sum+nums[i],target,nums,dp,ind);
        int minus = dfs(i+1,sum-nums[i],target,nums,dp,ind);
        
        return dp[i][sum + ind] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(2*sum + 1,-1));
        return dfs(0,0,target,nums,dp,sum);
    }
};