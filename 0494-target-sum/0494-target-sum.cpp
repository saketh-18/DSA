class Solution {
public:
    int dfs(int i, int sum, int &target, vector<int> &nums){
        if(i >= nums.size()){
            if(target == sum) return 1;
            return 0;
        }

        int plus = dfs(i+1,sum+nums[i],target,nums);
        int minus = dfs(i+1,sum-nums[i],target,nums);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0,0,target, nums);
    }
};