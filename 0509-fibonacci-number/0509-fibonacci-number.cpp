class Solution {
public:
    int fibh(vector<int> &dp, int n){
        if(n <= 1) return n;
        else {
            if(dp[n-1] != -1 && dp[n-2] != -1) return dp[n-1] + dp[n-2];
            if(dp[n-1] != -1) return dp[n-1] + fibh(dp,n-2);
            if(dp[n-2] != -1) return fibh(dp,n-1) + dp[n-2]; 
            dp[n] = fibh(dp,n-1) + fibh(dp,n-2);
            return dp[n];
        }  
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fibh(dp,n);
    }
};