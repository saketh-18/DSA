class Solution {
public:
    pair<int,int> check(string &str) {
        int m = 0, n = 0;
        int i = 0;
        while(m >= 0 && n >= 0 && i < str.size()){
            if(str[i] == '1') n++;
            else m++;
            i++;
        }
        return {m , n};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        pair<int,int> temp = check(strs[0]);
        for(int i = temp.first; i <= m; i++){
            for(int j = temp.second; j <= n; j++){
                dp[0][i][j] = 1;
            }
        }

        for(int i = 1; i < strs.size(); i++){
            pair<int,int> iter = check(strs[i]);
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    if(iter.second > k || iter.first > j) dp[i][j][k] = dp[i-1][j][k];  
                    else {
                        dp[i][j][k] = max(dp[i-1][j][k],1 + dp[i-1][j-iter.first][k-iter.second]);
                    } 
                }
            }
        }
        return dp[strs.size()-1][m][n];
    }
};