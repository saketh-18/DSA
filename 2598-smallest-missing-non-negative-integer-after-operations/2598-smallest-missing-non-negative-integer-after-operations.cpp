class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        //first store all frequencies, 
        //the start from 0 and check for MEX

        unordered_map<int,int> hash;

        for(int i : nums){
            int r = ((i%value) + value)%value;

            hash[r]++;
        }

        int ans = 0;

        while(hash[(ans%value)] > 0){
            hash[(ans%value)]--;
            ans++;
        }

        return ans;
    }
};