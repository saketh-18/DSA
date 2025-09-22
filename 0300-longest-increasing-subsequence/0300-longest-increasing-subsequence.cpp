class Solution {
public:
    int rec(int i, int last, vector<int> &nums, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;

        if(dp[i][last + 1] != -1) return dp[i][last + 1];

        int not_take = rec(i+1,last,nums,dp);
        int take = 0;
        if(last == -1 || nums[i] > nums[last]){
            take = 1 + rec(i+1,i,nums,dp);
        } 
        
        return dp[i][last + 1] = max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        //tabulation
        //base cases are handled by all 0 initialization

        int take = 0;
        int not_take = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            for(int j = i-1; j >= -1; j--){
                take = 0;
                not_take = dp[i+1][j+1];
                if(j == -1 || nums[i] > nums[j]){
                    take = 1 + dp[i+1][i+1];
                }
                
                dp[i][j+1] = max(take,not_take);
            }
        }
        return dp[0][0];
    }
};