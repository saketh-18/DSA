class Solution {
public:
    int numSub(string s) {
        long long cur = 0, ans = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                cur++;
            } else { 
                if(cur == 0) continue; 
                ans += ((long long)(cur*(cur+1)/2))%mod;
                cur = 0;
            }
        }
        if(cur > 0) ans += ((long long)cur*(cur+1)/2)%mod;
        return ans%mod;
    }
};