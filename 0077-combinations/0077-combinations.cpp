class Solution {
public:
    void dfs(int n, int k, vector<vector<int>> &ans, vector<int> &res){
        if(res.size() == k){
            ans.push_back(res);
            return ;
        }

        if(n <= 0 || res.size() > k) return;

        //take the current n and reduce the n and not take and reduce it
        if(res.size() < k){
            res.push_back(n);
            dfs(n-1,k,ans,res);
            res.pop_back();
        }

        dfs(n-1,k,ans,res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(n,k,ans,res);
        return ans;
    }
};