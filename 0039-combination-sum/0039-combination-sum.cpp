class Solution {
public:
    void recursion(int sum , int i, int target, vector<int> curr, vector<int> &nums, vector<vector<int>> &ans){
            if(sum == target) {
                ans.push_back(curr);
                return ;
            }
        if(i >= nums.size() || sum > target) return ;
        recursion(sum,i+1,target,curr,nums,ans);
        curr.push_back(nums[i]);
        sum += nums[i];
        recursion(sum,i,target,curr,nums,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //same as power set
        vector<vector<int>> ans;
        recursion(0,0,target,{},candidates,ans); 
        return ans;  
    }
};