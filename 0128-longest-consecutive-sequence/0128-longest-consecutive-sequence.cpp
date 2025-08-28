class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;

        for(int i : nums){
            if(st.find(i-1) == st.end()){
                int cur = 1;
                while(st.find(i+cur) != st.end()){
                    cur++;
                }
                ans = max(cur,ans);
            }
        }
        return ans;
    }
};