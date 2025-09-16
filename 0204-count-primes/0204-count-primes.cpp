class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<int> prime(n+1,0);
        prime[0] = 1;
        prime[1] = 1;
        int ans = 0;
        for(int i = 2; i * i < n; i++){
            if(prime[i] == 0){
                for(int j = i*i;j < n; j += i){
                    prime[j] = 1;
                }
            }
        }
        for(int i : prime){
            if(i == 0) ans++;
        }
        return ans-1;
    }
};