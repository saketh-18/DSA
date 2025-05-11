class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3){
            return false;
        }
        int odd = 0;
        for(int i = 0 ; i < arr.size(); i++){
            arr[i]%2 != 0 ? odd++ : odd = 0;
            if(odd == 3){
                return true;
            }
        }
        return false;
    }
};