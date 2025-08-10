class Solution {
public:
    bool rotateString(string s, string goal) {
        //concatenate two strings and find the original string s in the concatenated string
        if(s.length() != goal.length()) return false;
        string con = goal +  goal;
        int n = s.size();
        for(int i = 0; i <= n; i++){
            if(con.substr(i, n) == s) return true;
        }
        return false;
    }
};