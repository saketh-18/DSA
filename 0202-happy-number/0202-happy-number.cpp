class Solution {
public:
    int helper(int n){
        int val = 0;
        while(n > 0){
            val = val + (n%10)*(n%10);
            n = n/10;
        }
        return val;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n != 1 && seen.find(n) == seen.end()){
            seen.insert(n);
            n = helper(n);
        }
        return n == 1;
    }
};