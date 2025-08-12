class Solution {
public:
    void dfs(int i, vector<int> cur, vector<vector<int>> &ans, vector<int> &nums){
        if(i == nums.size()) {
            ans.push_back(cur);
            return ;
        }

        //take the current element
        cur.push_back(nums[i]);
        dfs(i+1,cur,ans,nums);
        cur.pop_back();
        //skip until find a new element
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        dfs(i+1,cur,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //take not take 
        //sort the list
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(0,{},ans,nums);
        return ans;
    }
};