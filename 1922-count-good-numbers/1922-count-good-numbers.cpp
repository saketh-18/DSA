#include <cmath>
class Solution {
public:
    const int mod = 1e9 + 7;
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base = base % mod;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }
    int countGoodNumbers(long long n) {
        
        long long even = (n + 1) / 2;  // number of even indices
        long long odd = n / 2;         // number of odd indices

        long long res = (modPow(5, even) * modPow(4, odd)) % mod;
        return (int)res;
    }
};