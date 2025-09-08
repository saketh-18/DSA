class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(),a.end());
        int len = s.size();
        vector<vector<int>> dp(len+1,vector<int>(len+1,0));
        //tabulation
        //basecases
        for(int i = 1; i <= len; i++){
            for(int j = 1; j <= len; j++){
                if(a[i-1] == s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[len][len];
    }
};