class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int , int> , int>> que;

        int rows = grid.size();
        int cols = grid[0].size();

        //storing positions of rotten oranges initially
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    que.push({{i , j} , 0});
                }
            }
        }

        // if(que.empty()) return -1;
        int time = 0;
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!que.empty()){
            int r = que.front().first.first;
            int c = que.front().first.second;
            int t = que.front().second;

            que.pop();

            time = max(time , t);

            // checking the adjacent positions of the rotten orange

            for(auto dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    que.push({{nr, nc}, t + 1});
                }
            }
        }

        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;

    }
};