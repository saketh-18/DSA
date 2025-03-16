class Solution {
public:
    string reverseWords(string s) {
        string temp = "" , ans = "";
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] != ' '){
                temp += s[i];
            }
            else if(!temp.empty()) {
                if(ans.empty()) {
                    ans = temp;
                }
                else {
                    ans = temp + " " + ans;
                }
                temp = "";
            }
            
        }
        if(!temp.empty()) {
        if(ans.empty()) {
                ans = temp;
            }
        else {
            ans = temp + " " + ans;
        }
        
        } 
        return ans; 
    }
};