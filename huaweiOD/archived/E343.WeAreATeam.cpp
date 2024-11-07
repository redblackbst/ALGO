#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class UnionFind {
    vector<int> root, rank;

public:
    UnionFind(int n) : root(n), rank(n) {
        iota(root.begin(), root.end(), 0);
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) {
                root[rx] = ry;
            } else if (rank[ry] < rank[rx]) {
                root[ry] = rx;
            } else {
                root[rx] = ry;
                rank[y]++;
            }
        }
    }

    int find(int x) {
        if (root[x] != x) {
            root[x] = find(root[x]);
        }
        return root[x];
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    if (n < 1 || n >= 100000 || m < 1 || m >= 100000) {
        cout << "Null" << endl;
    }
    for (int i = 0; i < m; i++) {
        int x, y, op;
        cin >> x >> y >> op;
        x--; y--;
        if (x < 0 || x >= n || y < 0 || y >= n || (op != 0 && op != 1)) {
            cout << "da pian zi" << endl;
            continue;
        }
        if (op == 0) {
            uf.unite(x, y);
        } else if (op == 1) {
            cout << (uf.isConnected(x, y) ? "We are a team" : "We are not a team") << endl;
        }
    }
}