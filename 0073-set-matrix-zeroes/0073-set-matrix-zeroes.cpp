class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zeroes;
        for(int i = 0 ; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    zeroes.push_back({i , j});
                }
            }
        }

        for (int i = 0; i < zeroes.size(); i++) {
            int row = zeroes[i][0];
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[row][j] = 0;
            }
        }

        // Set entire columns to zero
        for (int i = 0; i < zeroes.size(); i++) {
            int col = zeroes[i][1];
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][col] = 0;
            }
        }
        
    }
};