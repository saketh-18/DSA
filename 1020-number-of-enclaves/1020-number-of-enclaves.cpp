class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //start from the edge 1s
        // mark all edge ones and perform bfs for the connected ones;

        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int , int>> que;
        int ans = 0;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    ans++;
                    if(i == 0 || i == rows - 1 || j == 0 || j == cols-1){
                        ans--;
                        que.push({i , j});
                        grid[i][j] = -1;
                    }
                }
            }
        }

        while(!que.empty()){
            int row = que.front().first;
            int col = que.front().second;
            que.pop();

            vector<pair<int ,int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};
            for(auto i : dir){
                int nr = row + i.first;
                int nc = col + i.second;

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols){
                    if(grid[nr][nc] == 1) {
                        ans--;
                        que.push({nr , nc});
                        grid[nr][nc] = -1;
                    }
                }
            }

        }
        return ans;
        
    }
};