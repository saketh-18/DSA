class Solution {
public:
    int rec(int i, int j, string a, string b, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]){
            return dp[i][j] = rec(i-1,j-1,a,b,dp) + rec(i-1,j,a,b,dp);
        }

        return dp[i][j] = rec(i-1,j,a,b,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return rec(s.size()-1,t.size()-1,s,t,dp);
    }
};