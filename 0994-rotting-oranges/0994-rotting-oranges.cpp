class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //first traverse thru the grid and find any rotten orange
        //if any add them into que
        //in bfs maintain a minutes variable , increment it for every iteration,
        //at last traverse the grid again if any fresh orange found return -1 
        //else return the minutes

        queue<pair<int,int>> que;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        bool orange = false;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    que.push({i,j});
                }
                if(grid[i][j] == 1) orange = true;
            }
        }  

        if (que.empty() && orange) return -1;
        if (orange == false) return 0;  
        int minutes = 0; 
        while(!que.empty()){
            int size = que.size();

            for(int i = 0; i < size; i++){
                int row = que.front().first;
                int col = que.front().second;

                que.pop();

                for(auto pair : dir){
                    int nr = row + pair.first;
                    int nc = col + pair.second;

                    if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()){
                        if(grid[nr][nc] == 1){
                            grid[nr][nc] = 2;
                            que.push({nr,nc});
                        }
                    }
                }
            }
            minutes++;
        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0 ;j < grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return minutes-1;
    }
};