class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int placed = 0;
        for(int i = 0 ;i < fruits.size(); i++){
            for(int j = 0 ; j < baskets.size(); j++){
                if(baskets[j] >= fruits[i]){
                    placed++;
                    baskets[j] = 0;
                    break;
                }
            }
        }
        return fruits.size() - placed;
    }
};