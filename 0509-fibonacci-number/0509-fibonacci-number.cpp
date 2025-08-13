class Solution {
public:
    int fib(int n) {
        i(n <= 1) return n;
        int prev2 = 0 , prev = 1;
        for(int i = 2 ; i <= n; i++){
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};