class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //calculate prefix and suffix sums
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i]*prefix[i-1];
        }
        for(int i = n-2; i>= 0; i--){
            suffix[i] = nums[i]*suffix[i+1]; 
        }
        
        for(int i =  1; i < n-1; i++){
            nums[i] = prefix[i-1]*suffix[i+1];
        }

        nums[0] = suffix[1];
        nums[n-1] = prefix[n-2];
        return nums;
    } 
};