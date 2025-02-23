class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size() - 1;
        if(n == 0){
            return arr[0];
        }
        if(arr[0] != arr[1]){
            return arr[0];
        }
        else if(arr[n-1] != arr[n]) {
            return arr[n];
        }

        int low = 1 , high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
                return arr[mid];
            }
            else if(mid % 2 == 0){ // mid is even
                if(arr[mid] == arr[mid+1]){ // e-o
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            else { // mid is odd
                if(arr[mid] == arr[mid+1]){
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};