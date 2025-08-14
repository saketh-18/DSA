class Solution {
public:
    void dfs(vector<int> &nums, int exp, int &k, int &ans, int i){
        if(i == nums.size()){
            if(exp == k) ans++;
            return;
        }

        dfs(nums,exp+nums[i],k,ans,i+1);
        dfs(nums,exp-nums[i],k,ans,i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        dfs(nums,-nums[0],target,ans,1);
        dfs(nums,nums[0],target,ans,1);
        return ans;
    }
};