class Solution {
public:
    int rec(int i, int j, vector<int> &prices){
        if(j == prices.size()){
            i++;
            j = i + 1;
        }
        if(i == prices.size()){
            return 0;
        }

        int left = prices[j]-prices[i];
        if(left > 0){
            return left + rec(j,j+1,prices);
        } else {
            return rec(i+1,j+1,prices);
        }
    }
    int maxProfit(vector<int>& prices) {
        //for every day there are two possibilities 
        //to buy at the current prices and to sell at the current price
        //and store the profit  
        return rec(0,1,prices);
    }
};