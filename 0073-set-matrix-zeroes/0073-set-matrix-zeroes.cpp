class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //set zeroes in first row and col
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool isrow = false, iscol = false;
        bool isall = matrix[0][0] == 0;
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0){
                isrow = true;
                break;
            }
        }


        for(int i = 0 ; i < cols; i++){
            if(matrix[0][i] == 0){
                iscol = true;
                break;
            }
        }


        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        //set zero rows
        for(int i = 1; i < rows; i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < cols; j++){
                    matrix[i][j] = 0; 
                }
            }
        }

        //set zero cols
        for(int i = 1; i < cols; i++){
            if(matrix[0][i] == 0){
                for(int j = 0; j < rows; j++){
                    matrix[j][i] = 0;
                }
            }
        }

        if(isall){
            for(int i = 0 ; i < rows;i++){
                matrix[i][0] = 0;
            }
            for(int i = 0 ; i < cols;i++){
                matrix[0][i] = 0;
            }
        }

        if(isrow) {
            for(int i = 0 ; i < rows;i++){
                matrix[i][0] = 0;
            }
        }

        if(iscol){
            for(int i = 0 ; i < cols;i++){
                matrix[0][i] = 0;
            }
        }
    }
};