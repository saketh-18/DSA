class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int miss = 0;
        int t = 0;
        if(arr.size() == 1){
            if(arr[0] > k) return k;
            return k + 1;
        }
        if(arr[0] != 1){
            miss = arr[0]-1;
            if(miss >= k) return k;
        }

        for(int i = 1; i < arr.size(); i++){
            if(arr[i]-arr[i-1] != 1){
                miss += arr[i]-(arr[i-1]+1);
                t = arr[i];
            }
            if(miss >= k){
                return arr[i] - (miss-k+1);
            }
        }
        return arr[arr.size()-1] + k - miss;
    }
};