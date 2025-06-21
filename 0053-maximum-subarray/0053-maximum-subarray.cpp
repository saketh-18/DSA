class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 , maxSum = 0;
        int pos = 0 , neg = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > 0) pos++;
            else if(nums[i] < 0) neg++;
        }

        if((pos > 0 && neg > 0) || pos > 0 && neg == 0){
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maxSum = max(sum , maxSum);
            if(sum < 0){
                sum = 0;
            }
        } 
        }
        else {
            maxSum = nums[0];
            for(int i = 0 ; i < nums.size(); i++){
                maxSum = max(maxSum , nums[i]);
            }
        }
        return maxSum;
    }
};