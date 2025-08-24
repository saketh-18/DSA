class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = k;
        int len = 0;
        int i = 0, j = 0;
        while(j < nums.size()){
            if(nums[j] == 0){
                if(zero > 0){
                    zero--;
                    j++;
                    len = max(len,j-i);
                } else {
                    if(nums[i] == 0 && zero < k) zero++;
                    i++;
                    if(i > j) j = i;
                }
            } else {
                j++;
                len = max(len,j-i);
            }
        }
        return len;
    }
};