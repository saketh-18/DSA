class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        // tabulation
        // base case is setting the last index to true
        dp[n - 1] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j <= i + nums[i]; j++) {
                if ((j < n) && dp[j]) dp[i] = true;
            }
        }
        return dp[0];
    }
};