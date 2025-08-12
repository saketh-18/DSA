class Solution {
public:
    void rec(int sum , int k, int i , vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans){
        if(sum == k) {
            ans.push_back(curr);
            return ;
        }
        if(i >= nums.size() || sum > k) return;

        curr.push_back(nums[i]);
        rec(sum+nums[i],k,i+1,nums,curr,ans);
        curr.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
        rec(sum,k,i+1,nums,curr,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        rec(0,target,0,candidates,curr,ans);
        return ans;
    }
};