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
    int nConnected() {
        int n = 0;
        for (int i = 0; i < root.size(); i++) {
            if (root[i] == i) n++;
        }
        return n;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) uf.unite(i, j);
            }
        }
        return uf.nConnected();
    }
};