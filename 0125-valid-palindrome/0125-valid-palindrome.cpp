class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> st;
        for(int i = 0 ; i < s.size(); i++){
            if(isalnum(s[i])){
                st.push(tolower(s[i]));
            }
        }

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                if(tolower(s[i]) != st.top()){
                    return false;
                }
                st.pop();
            }
        }
        return true;
    }
};