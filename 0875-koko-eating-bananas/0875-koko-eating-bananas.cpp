class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //find max element and specify range of binary search

        int up = INT_MIN;
        for(int i : piles){
            up = max(i,up);
        }
        int mod = INT_MAX;
        int i = 1;
        int ans = INT_MAX;
        int mid = 0;
        while(i <= up){
            mid = (i+up)/2;
            long long cur = 0;
            for(int i : piles){
                if(i%mid == 0)  cur += (i/mid)%mod;
                else cur += (i/mid)+1;
            }
            if(cur > h){
                i = mid + 1;
            } else{
                 up = mid - 1;
                 ans = mid;
            }
        }
        return ans;
    }
};