#include "../utils/abel_macro.h"

class UnionFind {
public:
    vector<int> root, sz;
    int parts;

    UnionFind(int n) : root(n), sz(n, 1), parts(n) {
        ranges::iota(root, 0);
    }

    int find(int x) {
        if (x != root[x]) {
            root[x] = find(root[x]);
        }
        return root[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        parts--;
        if (sz[rx] < sz[ry]) {
            root[rx] = ry;
            sz[y] += sz[x];
        } else {
            root[ry] = rx;
            sz[rx] += sz[ry];
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        int unused = 0;
        for (auto e : connections) {
            int u = e[0], v = e[1];
            if (uf.isConnected(u, v)) {
                unused++;
            } else {
                uf.unite(u, v);
            }
        }
        int need = uf.parts - 1;
        if (unused < need) {
            return -1;
        }
        return need;
    }
};

int main() {
    Solution a;
    vector<vector<int>> conn{{1,5},{1,7},{1,2},{1,4},{3,7},{4,7},{3,5},{0,6},{0,6},{0,1},{0,4},{2,6},{0,3},{0,2}};
    int n = 12;
    int need = a.makeConnected(n, conn);
    cout << endl << need << endl;
}