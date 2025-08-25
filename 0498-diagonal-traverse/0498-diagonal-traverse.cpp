class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // diagonal  - down - {+1,-1}
        // diagonal  - up - {-1,+1}
        // direction change - right or down
        vector<int> ans;
        int flag = 0; // 0 means right 1 means down
        int i = 0, j = 0;
        int m = mat.size(), n = mat[0].size();
        while (i < m && j < n) {
            ans.push_back(mat[i][j]);
            if (i == m - 1 && j == n - 1)
                break;
            // check the flag and move
            // the flag is 0 so move on to upper diagonal
            // but the up side is not there so go right
            if (flag == 0) {
                // check up first
                int nr = i - 1;
                int nc = j + 1;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    i = nr;
                    j = nc;
                } else if(i >= 0 && i < m && j + 1 >= 0 && j + 1< n){ //check right
                    flag = 1;
                    j = j+1;
                } else { // if right is also out of bounds then down
                    flag = 1;
                    i++;
                }
            } else {
                //go to down first
                int nr = i + 1;
                int nc = j - 1;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    i = nr;
                    j = nc;
                } else if(i + 1 >= 0 && i + 1 < m && j < n && j >= 0){
                    flag = 0;
                    i++;
                } else{ //go right
                    flag = 0;
                    j++;
                }
            }
            cout << i << " " << j << endl;
        }
        return ans;
    }
};