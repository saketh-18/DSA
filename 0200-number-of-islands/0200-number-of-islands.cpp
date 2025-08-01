class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int,int>> q;
    q.push({r, c});
    grid[r][c] = '2';

    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                grid[nx][ny] = '2';
                q.push({nx, ny});
            }
        }
    }
}

    int numIslands(vector<vector<char>>& grid) {
        // vector<vector<int>> vis(grid.size() , vector<int>(grid[0].size(), -1));

        int count = 0;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    bfs(i , j , grid);
                    count++;
                }
            }
        }
        return count;
    }
};