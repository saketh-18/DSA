class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int cur = 0;
        vector<bool> ans(nums.size(), false);
        for(int i = 0; i < nums.size(); i++){
            cur = (cur * 2 + nums[i]) % 5;
            ans[i] = (cur == 0);
        }
        return ans;
    }
};