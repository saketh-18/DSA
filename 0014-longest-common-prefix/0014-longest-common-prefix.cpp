class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //sort the array of strings
        //compare first and last string
        //check the common prefix
        sort(strs.begin(), strs.end());
        string ans;
        for(int i = 0 ; i < min(strs[0].length() , strs[strs.size() - 1].size()); i++){
            if(strs[0][i] != strs[strs.size() - 1][i]){
                return ans;
            }
            ans += strs[strs.size() - 1][i];
        }
        return ans;
    }
};