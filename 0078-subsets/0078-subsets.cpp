class Solution {
public:
    void recursion(vector<int> &nums, vector<int> curr, int index , vector<vector<int>> &ans){
        if(index >= nums.size()){
            ans.push_back(curr);
            return ;
        }
        recursion(nums,curr,index+1,ans);
        curr.push_back(nums[index]);
        recursion(nums,curr,index+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //base case in recursion : if index == n push the current subsequence
        //two other cases add the current index or not add the current index

        vector<vector<int>> ans;
        recursion(nums,{},0,ans);
        return ans;
    }
};