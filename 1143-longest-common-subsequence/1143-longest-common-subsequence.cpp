class Solution {
public:
    int rec(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]){
            return dp[i][j] =  1 + rec(i-1,j-1,a,b,dp);
        } 

        return dp[i][j] =  max(rec(i-1,j,a,b,dp),rec(i,j-1,a,b,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
        return rec(text1.length()-1,text2.length()-1,text1,text2,dp);
    }
};