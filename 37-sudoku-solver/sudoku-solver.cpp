class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') continue;

                for (char ch = '1'; ch <= '9'; ch++) {
                    bool valid = true;

                    for (int i = 0; i < 9; i++) {
                        if (board[r][i] == ch || board[i][c] == ch) {
                            valid = false;
                            break;
                        }
                    }

                    int sr = (r / 3) * 3;
                    int sc = (c / 3) * 3;

                    for (int i = sr; i < sr + 3 && valid; i++) {
                        for (int j = sc; j < sc + 3; j++) {
                            if (board[i][j] == ch) {
                                valid = false;
                                break;
                            }
                        }
                    }

                    if (valid) {
                        board[r][c] = ch;

                        if (solve(board))
                            return true;

                        board[r][c] = '.';
                    }
                }

                return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};