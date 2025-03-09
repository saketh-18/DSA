#include <bits/stdc++.h>
class Solution {
public:
    int shipWithinDays(vector<int>& arr, int d) {
        int maxArray = *max_element(arr.begin() , arr.end());
        int sumArray = accumulate(arr.begin() , arr.end() , 0);

        int low = maxArray , high = sumArray;
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int load = 0 , days = 1;
            for(int i =0; i < arr.size() ; i++){
                if(load+arr[i] > mid){
                    days++;
                    load = 0;
                }
                    load += arr[i];
            }

            if(days <= d){
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