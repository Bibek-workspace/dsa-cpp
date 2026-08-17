class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        parent[a] = b;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &e : edges) {
            if (!unite(e[0], e[1]))
                return e;
        }

        return {};
    }
};