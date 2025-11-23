class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            count = 0;
            for(int j = i; j < i + n; j++){
                count += nums[j%n];
                ans = max(ans,count);
            }
        }
        return ans;
    }
};