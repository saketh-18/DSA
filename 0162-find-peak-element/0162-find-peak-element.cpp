class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //if mid is greater than both left and right elements it is the peak

        int i = 0, j = nums.size() - 1, mid = (i+j)/2;
        while(i <= j){
            mid = (i+j)/2;

            bool left = true, right = true;
            if(mid-1 >= 0 && nums[mid] < nums[mid-1]) left = false;
            if(mid + 1 < nums.size() && nums[mid] < nums[mid+1]) right = false;
            if(left && right) return mid;

            if(nums[mid] < nums[mid+1]) i = mid+1;
            else if(nums[mid] > nums[mid+1]) j = mid;
        }
        return mid;
    }
};