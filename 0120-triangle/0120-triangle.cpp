class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //tabulation
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(),-1));
        dp[0][0] = triangle[0][0];
        for(int i = 0 ; i < triangle.size(); i++){
            for(int j = 0 ; j < triangle[i].size(); j++){
                if(i == 0 && j == 0) continue;
                
                if(j >= 1 && j < triangle[i].size()-1){
                    dp[i][j] = min(triangle[i][j] + dp[i-1][j] , triangle[i][j] + dp[i-1][j-1]);
                } else if(j == triangle[i].size() - 1){
                    dp[i][j] = triangle[i][j]+dp[i-1][j-1];
                } else {
                    dp[i][j] = triangle[i][j]+dp[i-1][j];
                }
            }
        }
        int minsum = INT_MAX;
        for(int i = 0 ; i < triangle.size(); i++){
            minsum = min(dp[triangle.size()-1][i] , minsum);
        }
        return minsum;
    }
};