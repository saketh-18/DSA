class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2)
                    que.push({i, j});
            }
        }

        int minutes = 0;
        while (!que.empty()) { 
            vector<pair<int, int>> vec = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            int size = que.size();
            for(int s = 0 ; s < size ; s++) {
                int rows = que.front().first;
                int cols = que.front().second;
                que.pop();
                for (auto i : vec) {
                    int nr = rows + i.first;
                    int nc = cols + i.second;

                    if (nr >= 0 && nr < row && nc >= 0 && nc < col) {
                        if (grid[nr][nc] == 1) {
                            grid[nr][nc] = 2;
                            que.push({nr, nc});
                        }
                    }
                }
            }
            if(!que.empty()) minutes++;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return minutes;
    }
};