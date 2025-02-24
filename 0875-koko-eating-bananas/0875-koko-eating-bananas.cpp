class Solution {
public:
    int minEatingSpeed(vector<int>& v, int h) {
        int maxnum = 0  , ans = 0;
    for(int i = 0 ; i < v.size(); i++){
        maxnum = max(maxnum , v[i]);
    }

    // range of ans would be from 1 to maxnum;
    int low = 1 , high = maxnum;
    while(low <= high){
        int mid = low + (high - low) / 2;
        long long hours = 0;
        for(int i = 0 ; i < v.size(); i++){
            hours += (v[i] + mid - 1) / mid; 
        }
        if(hours <= h){
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
    }
};