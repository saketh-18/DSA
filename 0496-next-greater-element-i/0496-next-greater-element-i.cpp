class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> map;
        stack<int> st;
        
        for(int i = nums2.size() - 1;i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            !st.empty() ? map[nums2[i]] = st.top() : map[nums2[i]] = -1;
            st.push(nums2[i]);
        }

        for(int i = 0 ; i < nums1.size(); i++){
            nums1[i] = map[nums1[i]];
        }

        return nums1;
    }
};