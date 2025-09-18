class Solution {
public:
    int rec(int i, vector<int> &nums, int last, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;

        if(dp[i][last + 1] != -1) return dp[i][last + 1];

        int not_take = rec(i+1,nums,last,dp);

        int take = 0;
        if(last == -1 || nums[i] > nums[last]){
            take = 1 + rec(i+1,nums,i,dp);
        }

        return dp[i][last + 1] = max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return rec(0,nums, -1,dp);
    }
};