class Solution {
public:
    int binary(vector<int> &arr, long long k){
        int ans = -1;
        int l = 0, h = arr.size()-1;
        while(l <= h){
            int mid = (l + h)/2;
            if((long long)arr[mid] >= k){
                ans = mid;
                h = mid-1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        int count = 0;
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++){
            long long n = (success + spells[i] - 1) / spells[i]; 
           int func = binary(potions, n);
           if(func == -1){
            pairs.push_back(0);
           } else pairs.push_back(potions.size() - func);
        }
        return pairs;
    }
};