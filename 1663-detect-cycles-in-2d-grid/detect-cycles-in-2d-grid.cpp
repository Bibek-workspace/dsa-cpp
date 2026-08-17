class Solution {
public:
    int m, n;
    vector<vector<bool>> vis;
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    bool dfs(vector<vector<char>>& grid, int r, int c, int pr, int pc) {
        vis[r][c] = true;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (grid[nr][nc] != grid[r][c])
                continue;

            if (nr == pr && nc == pc)
                continue;

            if (vis[nr][nc])
                return true;

            if (dfs(grid, nr, nc, r, c))
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vis.assign(m, vector<bool>(n, false));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!vis[r][c] && dfs(grid, r, c, -1, -1))
                    return true;
            }
        }

        return false;
    }
};