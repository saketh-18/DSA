class Solution {
public:
    int next(vector<int> arr , int n , int x){
        for(int i = n ; i < arr.size(); i++){
            if(arr[i] > x){
                return arr[i];
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0 ; i < nums1.size(); i++){
            for(int j = 0 ; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(next(nums2 , j , nums2[j]));
                }
            }
        }
        return ans;
    }
};