class Solution {
public:
    
    void recursion(string curr , int n  , int l , int r , vector<string> &res){
        if(l == n && r == n){
            res.push_back(curr);
            return;
        }
        if(l < n){
            recursion(curr + '(' , n , l+1 , r , res);
        }
        if(r < l){
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