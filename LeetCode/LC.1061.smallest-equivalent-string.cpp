#include "../utils/abel_macro.h"

class UnionFind {
    vector<int> root;
public:
    UnionFind() : root(26) {
        for (int i = 0; i < 26; i++) {
            root[i] = i;
        }
    }
    int find(int x) {
        return root[x] == x ? x : find(root[x]);
    }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rx < ry) {
            root[ry] = rx;
        } else {
            root[rx] = ry;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf;
        for (int i = 0; i < s1.length(); i++) {
            uf.unite(s1[i] - 'a', s2[i] - 'a');
        }
        for (char& c : baseStr) {
            c = uf.find(c - 'a') + 'a';
        }
        return baseStr;
    }
};