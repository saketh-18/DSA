class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        for(int i = 0 ; i < s.length(); i++){
            vector<int> hash(256 , 0);
            // count = 0;
            for(int j = i; j < s.length(); j++){
                if(hash[s[j]] > 0) break;
                hash[s[j]]++;
                count = max(count , j - i + 1);
            }
        }
        return count;
    }
};