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
        // vector<int> dp(nums.size(),-1);
        // return dfs(nums.size()-1,nums,dp);
        //tabulation => 
        // dp[0] = nums[0];
        // for(int i = 1; i < nums.size(); i++){
        //     if(i < 2){
        //         dp[i] = max(nums[i],nums[i-1]);
        //     } else {
        //         dp[i] = max(dp[i-1] , nums[i]+dp[i-2]);
        //     }
        // }
        //space optimization approach =>

        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[1],nums[0]);
        int prev = max(nums[1],nums[0]), prev2 = nums[0];

        for(int i = 2; i < nums.size(); i++){
            int cur = max(nums[i] + prev2 , prev);
            prev2 = prev;
            prev = cur;
        }
        return prev;
        // return dp[nums.size() - 1];
    }
};