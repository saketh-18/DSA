class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1){
            return 0;
        }
        else {
            int l = prices[0] , len = 0 , sum = 0;
            for(int i = 1; i < prices.size(); i++){
                if(prices[i] - l > 0){
                    sum = prices[i] - l;
                    len = max(len , sum);
                }
                else {
                    l = prices[i];
                }
            }
            return len;
        }
        return 0;
    }
};