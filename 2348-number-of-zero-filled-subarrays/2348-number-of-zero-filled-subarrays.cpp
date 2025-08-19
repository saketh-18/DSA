class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum = 0 ;
        long long streak = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] != 0){
                sum += (streak*(streak+1))/2;
                streak = 0;
            } else {
                streak++;
            }
        }
        return sum += (streak*(streak+1))/2;
    }
};