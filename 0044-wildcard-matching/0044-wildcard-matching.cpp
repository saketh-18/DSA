class Solution {
public:
    bool dfs(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i == s.length() && j == p.length()) return true;

        if(i > s.length() || j > p.length()) return false;

        if(dp[i][j] != -1) return dp[i][j];
        if(isalnum(p[j])){
            if(s[i] == p[j]){
                dp[i][j] = dfs(i+1,j+1,s,p,dp);
            } else return false;
        }

        if(p[j] == '*'){
            return dp[i][j] = dfs(i+1,j,s,p,dp) || dfs(i,j+1,s,p,dp);
        }
        return dp[i][j] = dfs(i+1,j+1,s,p,dp);
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1,vector<int>(p.length() + 1,-1));
        return dfs(0,0,s,p,dp);
    }
};