class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int x = k;
        for(int i : nums) {
            if(i == 1){
                if(x < k){
                    return false;
                } else x = 0;
            } else x++;
        }
        return true;
    }
};