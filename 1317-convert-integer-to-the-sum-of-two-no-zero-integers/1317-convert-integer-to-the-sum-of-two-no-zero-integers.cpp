class Solution {
public:
    bool check(int n){
        if(n/10 == 0) return n == 0;
        while(n > 0){
            if(n%10 == 0) return true;
            n = n/10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            if(!check(i)){
                if(!check(n-i)){
                    return {i,n-i};
                }
            }
        }
        return {};
    }
};