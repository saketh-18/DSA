class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;  // Use long long to avoid overflow for INT_MIN
        double ans = 1.0;
        bool isNegative = false;
        
        if (nn < 0) {
            isNegative = true;
            nn = -nn;
        }

        while (nn > 0) {
            if (nn % 2 == 1) {
                ans *= x;
            }
            x *= x;
            nn /= 2;
        }

        return isNegative ? 1.0 / ans : ans;
    }
};
