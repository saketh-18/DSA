class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);

        //tabulation 
        //base case
        dp[0] = nums[0];
        int skip = 0;
        int take = nums[1];
        for(int i = 1; i < nums.size(); i++){
            skip = dp[i-1];
            if(i > 1) take = nums[i] + dp[i-2];
            dp[i] = max(skip,take);
        }
        return dp[nums.size()-1];
    }
};