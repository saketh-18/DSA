class Solution {
public:
int bfs(int r, int c, vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int,int>> q;
    q.push({r, c});
    int count = 1;
    grid[r][c] = 2;

    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                q.push({nx, ny});
                count++;
            }
        }
    }
    return count;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0 , area = 0;

        for(int i = 0 ;i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    area = bfs(i ,j,grid);
                    maxArea = max(maxArea , area);
                }
            }
        }
        return maxArea;
    }
    
};