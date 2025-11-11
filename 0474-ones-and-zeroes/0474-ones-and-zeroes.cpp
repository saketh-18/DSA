class Solution {
public:
    pair<int,int> check(string &str, int m, int n) {
        if(m == 0 && n == 0) return {-1, -1};
        int i = 0;
        while(m >= 0 && n >= 0 && i < str.size()){
            if(str[i] == '1') n--;
            else m--;
            i++;
        }
        if(m >= 0 && n >= 0) return {m, n};
        else return {-1,-1};
    }
    int helper(int i, vector<string> &strs, int m, int n, vector<vector<vector<int>>>  &dp){
        if(i == 0){
            pair<int,int> chk = check(strs[i], m, n);
            if(chk.first == -1 && chk.second == -1) return 0;
            else return 1;
        }

        if(m < 0 || n < 0) return 0;

        if(dp[i][m][n] != -1) return dp[i][m][n];
        //take / not take
        int take = 0;
        //for take we need to check
        pair<int,int> temp = check(strs[i], m, n);
        if(temp.first != -1) {
            take =  1 + helper(i-1,strs, temp.first, temp.second, dp);
        } 

        int not_take = helper(i-1, strs, m, n, dp);
        return dp[i][m][n] = max(take, not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(strs.size() - 1, strs, m, n, dp);
    }
};