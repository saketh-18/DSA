class Solution {
public:
    int scoreOfString(string s) {
        int val = 0;
        for(int i = 0 ; i < s.length() - 1; i++){
            val += max(int(s[i]) , int(s[i+1])) - min(int(s[i]) , int(s[i+1]));
        }
        return val;
    }
};