class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size() - 1;
        int cols = grid[0].size() - 1;
        queue<pair<int , int>> que;
        // vector<vector<bool>> visited(rows + 1 , vector<bool>())

        for(int i = 0 ; i <= rows; i++){
            for(int j = 0; j <= cols; j++){
                if(grid[i][j] == 1){
                    ans++;
                    if((i == 0 || j == 0 || i == rows  || j == cols)){
                        que.push({i , j});
                        ans--;
                        grid[i][j] = -1;
                    }
                }
            }
        }

        

        while(!que.empty()){
            int r = que.front().first;
            int c = que.front().second;
            que.pop();

            vector<pair<int , int>> dir = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

            for(auto i : dir){
                int nr = r + i.first;
                int nc = c + i.second;

                if(nc >= 0 && nc <= cols && nr >= 0 && nr <= rows){
                    if(grid[nr][nc] == 1){
                        que.push({nr , nc});
                        ans--;
                        grid[nr][nc] = -1;
                    }
                }
            }

        }
        return ans;

    }
};