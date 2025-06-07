class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int, int>> que;

        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') {
                que.push({0, j});
                board[0][j] = '1';
            }
            if (board[rows - 1][j] == 'O') {
                que.push({rows - 1, j});
                board[rows - 1][j] = '1';
            }
        }

        // First and last columns
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') {
                que.push({i, 0});
                board[i][0] = '1';
            }
            if (board[i][cols - 1] == 'O') {
                que.push({i, cols - 1});
                board[i][cols - 1] = '1';
            }
        }

        while (!que.empty()) {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();

            vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for (auto i : dir) {
                int nr = r + i.first;
                int nc = c + i.second;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    if (board[nr][nc] == 'O') {
                        que.push({nr, nc});
                        board[nr][nc] = '1';
                    }
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};