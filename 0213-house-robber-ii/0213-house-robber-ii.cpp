class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];

        //without last element
        int take = 0;
        int not_take = 0;
        int iminus1 = nums[0];
        int iminus2 = 0;
        for(int i = 1; i < nums.size() - 1; i++){
            take = nums[i];
            if(i > 1) take += iminus2;
            not_take = iminus1;
            int curr = max(not_take,take);
            iminus2 = iminus1;
            iminus1 = curr;
        }

        int ans1 = iminus1;
        //without first element
        iminus1 = nums[1];
        iminus2 = 0;
        for(int i = 2; i < nums.size(); i++){
            take = nums[i];
            if(i > 2) take += iminus2;
            not_take = iminus1;

            int curr = max(take,not_take);
            iminus2 = iminus1;
            iminus1 = curr;
        }

        int ans2 = iminus1;

        return max(ans2, ans1);
    }
};