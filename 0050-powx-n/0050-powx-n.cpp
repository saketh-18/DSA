class Solution {
public:
    double recursion(long long n , double ans , double x){
        if(n <= 0) return ans;
        if(n%2 == 1) ans = ans*x;
        x = x*x;
        return recursion(n/2,ans , x);
    }
    double myPow(double x, int n) {
        long long nTemp = n;
        double ans = 1.0;
        bool isNeg = false;
        if(n < 0){
            nTemp = -nTemp;
            isNeg = true;
        }
        double res = recursion(nTemp , ans , x);
        return isNeg ? 1.0 / res: res;
    }
};