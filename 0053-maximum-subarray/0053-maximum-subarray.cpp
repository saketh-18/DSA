class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane's algo
        int ans = nums[0];
        int count = 0;

        for(int i : nums){
            if(count < 0) count = 0;
            count += i;
            ans = max(ans,count);
        }
        return ans;
    }
};