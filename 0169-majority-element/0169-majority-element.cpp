class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1,el = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(el == nums[i]) count++;
            else {
                if(count == 0){
                    el = nums[i];
                    count = 1;
                } else count--;
            }
        }
        return el;
    }
};