class Solution {
public:
    int smallestDivisor(vector<int>& arr, int limit) {
         int max1 = *max_element(arr.begin(), arr.end());

	int low = 1 , high = max1;
	int cnt = 0 , ans = 0;
	while(low <= high) {
		cnt = 0;
		int mid = (low + high) / 2;

		for(int i = 0; i < arr.size(); i++){
			if (arr[i] == 0) continue; // Ignore 0s to avoid division by zero
            cnt += (arr[i] + mid - 1) / mid;
		}

		if(cnt <= limit) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid+1;
		}
	}
	return ans;
    }
};