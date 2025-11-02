class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        // if represent guard as 1 , represent wall as 2, represent all blocks blocked as 1 
        for(int i = 0; i < guards.size(); i++){
            grid[guards[i][0]][guards[i][1]] = 1;
        }
        for(int i = 0; i < walls.size(); i++){
            grid[walls[i][0]][walls[i][1]] = 2;
        }

        //now fill all four directions of guards to 1; they are guarded
        for(int i = 0; i < guards.size(); i++){
            //right
            int row = guards[i][0];
            int col = guards[i][1];
            for(int right = col; right < n; right++){
                if(grid[row][right] == 2) break;
                grid[row][right] = 1;
            }
            for(int left = col; left >= 0; left--){
                if(grid[row][left] == 2) break;
                grid[row][left] = 1;
            }
            for(int top = row; top >= 0; top--){
                if(grid[top][col] == 2) break;
                grid[top][col] = 1;
            }
            for(int bottom = row; bottom < m; bottom++){
                if(grid[bottom][col] == 2) break;
                grid[bottom][col] = 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    ans++; 
                }
            }
        }
        return ans;
    }
};