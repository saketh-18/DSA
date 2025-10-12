class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 0, prev = 1;
        for(int i = 1; i <= n; i++){
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};