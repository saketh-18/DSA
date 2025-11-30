class Solution {
public:
    void dfs(int i, vector<int> candidates, vector<vector<int>> &ans, vector<int> res, int target){
        if(target == 0){
            ans.push_back(res);
            return ;
        }
        if(target < 0 || i >= candidates.size()) return;

        //take and not_take
        if(target >= candidates[i]){
            res.push_back(candidates[i]);
            dfs(i,candidates, ans, res, target-candidates[i]);
            res.pop_back();
        }
        dfs(i+1,candidates,ans,res,target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        dfs(0,candidates,ans,{},target);
        return ans;
    }
};