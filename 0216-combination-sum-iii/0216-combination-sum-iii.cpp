class Solution {
public:
    void dfs(int sum, int i, int n, int k, vector<int> &cur, vector<vector<int>> &ans){
        if(cur.size() == k){
            if(sum == n){
                ans.push_back(cur);
            }
            return;
        }

        if(i > 9 || sum > n) return;

        dfs(sum,i+1,n,k,cur,ans);
        cur.push_back(i);
        dfs(sum+i,i+1,n,k,cur,ans); 
        cur.pop_back();
        }
    vector<vector<int>> combinationSum3(int k, int n) {
        //take not take 
        //with a condition
        vector<int> cur;
        vector<vector<int>> ans;
        dfs(0,1,n,k,cur,ans);
        return ans;
    }
};