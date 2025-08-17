class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[1],nums[0]);
        int prev = max(nums[1],nums[0]), prev2 = nums[0];

        for(int i = 2; i < nums.size() - 1; i++){
            int cur = max(nums[i] + prev2 , prev);
            prev2 = prev;
            prev = cur;
        }

        int first = prev;

        prev = max(nums[2],nums[1]);
        prev2 = nums[1];
        for(int i = 3; i < nums.size(); i++){
            int cur = max(nums[i] + prev2 , prev);
            prev2 = prev;
            prev = cur;
        }
        int second = prev;

        return max(first,second);
        // return dp[nums.size() - 1];
    }
};