class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force
        //computing difference for every pair of i and j (indices) and finding max among them   
        int ans = 0;

        for(int i = 0; i < prices.size(); i++){
            for(int j = i + 1; j < prices.size(); j++){
                ans = max(ans , prices[j]-prices[i]);
            }
        }
        return ans;
    }
};