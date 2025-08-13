class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 1;

        if(n-1 >= 0 && n-2 >= 0) return climbStairs(n-1) + climbStairs(n-2);
        return climbStairs(n-1);
    }
};