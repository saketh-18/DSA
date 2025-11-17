class Solution {
public:
    bool checkValidString(string s) {
        int star = 0;
        stack<int> st;

        for(char c : s){
            if(c == '(') st.push('(');
            else if(c == ')') {
                if(!st.empty()){
                    st.pop();
                } else {
                    if(star > 0) star--;
                }
            } else {
                star++;
            }
        }

        if(st.empty()) return true;
        if(star >= st.size()) return true;
        return false;
    }
};