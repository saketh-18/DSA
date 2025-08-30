class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for rows
        for (int i = 0; i < 9; i++) {
            vector<char> freq(10, '0');
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (freq[board[i][j] - '0'] != '0')
                    return false;
                else
                    freq[board[i][j] - '0'] = '1';
            }
        }

        // for cols;
        for (int i = 0; i < 9; i++) {
            vector<char> freq(10, '0');
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.')
                    continue;
                if (freq[board[j][i] - '0'] != '0')
                    return false;
                else
                    freq[board[j][i] - '0'] = '1';
            }
        }

        // for grids
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {
                vector<char> freq(10, '0');
                for (int i = r; i < r + 3; i++) {
                    for (int j = c; j < c + 3; j++) {
                        if (board[i][j] == '.')
                            continue;
                        if (freq[board[i][j] - '0'] != '0')
                            return false;
                        freq[board[i][j] - '0'] = '1';
                    }
                }
            }
        }

        return true;
    }
};