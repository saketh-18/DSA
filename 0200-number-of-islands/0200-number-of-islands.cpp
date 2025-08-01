class Solution {
public:
    void dfs(pair<int ,int> pos, vector<vector<char>> &grid){
        int row = pos.first;
        int col = pos.second;
        grid[pos.first][pos.second] = '2';

        vector<pair<int , int>> rows = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto i : rows){
            int nr = row + i.first;
            int nc = col + i.second;

            if(nr < grid.size() && nr >= 0 && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == '1'){
                dfs({nr , nc} , grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // vector<vector<int>> vis(grid.size() , vector<int>(grid[0].size(), -1));

        int count = 0;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs({i , j} , grid);
                    count++;
                }
            }
        }
        return count;
    }
};