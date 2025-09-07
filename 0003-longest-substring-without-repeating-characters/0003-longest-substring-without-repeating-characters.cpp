class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> first;
        int i = 0;
        int cur = 1;
        int ans = 0, count = 0;
        int start = 0;
        while(i < s.length()){
            if(first[s[i]] != cur){
                first[s[i]] = cur;
                count++;
                ans = max(count,ans);
            } else {
                start++;
                i = start;
                cur++;
                first[s[i]] = cur;
                count = 1;
            }
            i++;
        }   
        return ans;
    }
};