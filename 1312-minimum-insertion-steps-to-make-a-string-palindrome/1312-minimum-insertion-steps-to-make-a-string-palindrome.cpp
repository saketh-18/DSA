class Solution {
public:
    int rec(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]){
            return dp[i][j] = 1 + rec(i-1,j-1,a,b,dp);
        }
        return dp[i][j] = max(rec(i-1,j,a,b,dp) ,rec(i,j-1,a,b,dp));
    }
    int minInsertions(string s) {
        string a = s;
        reverse(a.begin(),a.end());
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return n - rec(n-1,n-1,s,a,dp);
    }
};