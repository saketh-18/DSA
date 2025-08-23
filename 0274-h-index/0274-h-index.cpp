class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 0;i < n;i++){
            if(arr[i] >= n - i){
                return n-i;
            }
        }
        return 0;
    }
};
