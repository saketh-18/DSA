class Solution {
public:
    int countOdds(int low, int high) {
        if(high == low){
            if(high%2 != 0) return 1;
            return 0;
        }
        
        if(high%2 == 0 && low %2 == 0){
            return (high - low)/2;
        }
        // if(high%2 == 0 || low%2 == 0){
        //     return ()
        // }
        return (high - low)/2  + 1;
    }
};