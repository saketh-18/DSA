class Solution {
public:
    bool valid(string paren) {
    stack<char> st;

    for(int i = 0; i < paren.size(); i++) {
        if(paren[i] == '(') {
            st.push('(');
        } 
        else if(paren[i] == ')') {
            if(st.empty() || st.top() != '(') {
                return false;
            }
            st.pop(); 
        }
    }
    return st.empty();
}
    void recursion(string curr , int n  , int l , int r , vector<string> &res){
        if(l == n && r == n){
            if(valid(curr)){
                res.push_back(curr);
            }
            return;
        }
        if(l < n){
            recursion(curr + '(' , n , l+1 , r , res);
        }
        if(r < n){
            recursion(curr + ')' , n , l , r+1 , res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        recursion(curr , n , 0, 0, res);
        return res;
    }
};