class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int index) {

        if (index == word.length()) {
            return true;
        }

        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';  // mark visited

        bool found =
            dfs(board, word, r + 1, c, index + 1) ||  // down
            dfs(board, word, r - 1, c, index + 1) ||  // up
            dfs(board, word, r, c + 1, index + 1) ||  // right
            dfs(board, word, r, c - 1, index + 1);    // left

        board[r][c] = temp;  // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (dfs(board, word, i, j, 0)) {
                    return true;
                }

            }
        }

        return false;
    }
};