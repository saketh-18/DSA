class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0 , j = i + 1;
        int semaphore = 0;
        while(j < nums.size()){
            if(nums[i] == nums[j]){
                if(semaphore == 0){
                    nums[i+1] = nums[j];
                    i++;
                    semaphore = 1;
                }
                j++;
            } else {
                nums[i+1] = nums[j];
                i++;
                j++;
                semaphore = 0;
            }
        }
        return i+1;
    }
};