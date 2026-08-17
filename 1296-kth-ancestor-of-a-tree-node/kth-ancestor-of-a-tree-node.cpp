class TreeAncestor {
public:
    vector<vector<int>> up;
    int LOG;

    TreeAncestor(int n, vector<int>& parent) {
        LOG = 16;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            up[0][i] = parent[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[j - 1][i] != -1)
                    up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                node = up[j][node];

                if (node == -1)
                    return -1;
            }
        }

        return node;
    }
};