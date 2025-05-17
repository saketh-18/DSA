class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        long long num = 0;
        int i = 0;
        while(i < digits.size()){
            num = num*10 + digits[i];
            i++;
        }
        num++;
        while(num > 0){
            res.push_back(num%10);
            num = num/10;
        }
        reverse(res.begin() ,res.end());
        return res;
    }
};