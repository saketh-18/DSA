class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size() , -1);
        stack<int> st;

        for (int i = nums.size() + nums.size(); i >= 0; i--) {
            int index = i%nums.size();
            while (!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }

            st.empty() ? res[index] = -1 : res[index] = st.top();

            st.push(nums[index]);
        }

        return res;
    }
};