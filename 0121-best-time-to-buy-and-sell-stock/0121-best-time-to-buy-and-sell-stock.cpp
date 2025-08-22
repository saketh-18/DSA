class Solution {
public:
    int maxProfit(vector<int>& prices) {
            int l = prices[0] , len = 0;
            for(int i = 1; i < prices.size(); i++){
                if(prices[i] > l){
                    len = max(len , prices[i] - l); 
                }
                else {
                    l = prices[i];
                }
            }
            return len;
    }
};