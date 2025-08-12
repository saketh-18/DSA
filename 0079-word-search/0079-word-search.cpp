class Solution {
public:
    
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(int i , int j , vector<vector<char>> &board, string word , int k){
        if (board[i][j] != word[k]) return false;       // check current cell
        if (k == word.size() - 1) return true; 

        char temp = board[i][j];
        board[i][j] = '#';


        for(auto n : dir){
            int nr = i + n.first;
            int nc = j + n.second;

            if(nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size()){
                if(board[nr][nc] == word[k+1]){
                    if(dfs(nr,nc,board,word,k+1)) {
                        board[i][j] = temp;
                        return true; 
                    }
                }
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        //search for the starting letter
        char start = word[0];
        int rows = board.size() , cols = board[0].size();
        queue<pair<pair<int,int>,int>> que;
        for(int i = 0 ;i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};