class Solution {
public:
    int maxDepth(string s) {
        int count = 0 , maxCount = 0;
        stack<char> st;

        for(char c : s){
            if(c == '('){
                st.push('(');
                count++;
                maxCount = max(count,maxCount);
            } else if(c == ')'){
                st.pop();
                count--;
            }            
        }
        return maxCount;
    }
};