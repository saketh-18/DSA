class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int> ans(nums.size() , 0);
        // for(int i = 0 ;i < nums.size(); i++){
        //     ans[(i+k)%nums.size()] = nums[i];
        // }
        // for(int i =0 ; i < nums.size(); i++){
        //     nums[i] = ans[i];
        // }
        int n = nums.size();
        k = k%n;

        reverse(nums.begin() , nums.end());
        reverse(nums.begin() , nums.begin() + k);
        reverse(nums.begin() + k , nums.end());
    }
};