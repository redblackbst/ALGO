#include "../utils/abel_macro.h"

class UnionFind {
    vector<int> root;
    vector<int> rank;
public:
    UnionFind(int n) : root(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }
    int find(int x) {
        return root[x] == x ? x : find(root[x]);
    }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) {
            root[rx] = ry;
        } else if (rank[ry] < rank[rx]) {
            root[ry] = rx;
        } else {
            root[ry] = rx;
            rank[rx]++;
        }
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        UnionFind uf(n);
        for (auto& e : edges) {
            uf.unite(e[0], e[1]);
        }
        return uf.isConnected(source, destination);
    }
};