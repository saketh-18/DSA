class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0 , high = arr.size() - 1;
        int ans = arr[low];

        while(low <= high){
            int mid = (low + high) / 2;

            if(arr[low] <= arr[high]){
                ans = min(arr[low] , ans);
                return ans;
            } 
            
            if(arr[low] <= arr[mid]){
                ans = min(arr[low] , ans);
                low = mid + 1;
            }
            else {
                ans = min(arr[mid] ,ans);
                high = mid - 1;
            }
        }
        return ans;
    }
};