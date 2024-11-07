#include "../utils/abel_macro.h"

class UnionFind {
    vector<int> root;
public:
    UnionFind() : root(256) {
        for (int i = 0; i < 256; i++) {
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

int main() {
    string inputStr, outputStr = "";
    cin >> inputStr;
    UnionFind uf;
    unordered_set<char> cs;
    char c0;
    bool inParen = false;
    for (char c : inputStr) {
        if (c == '(') {
            c0 = '0';
            inParen = true;
        } else if (c == ')') {
            inParen = false;
        } else if (inParen) {
            cs.insert(c);
            if (c0 == '0') {
                c0 = c;
            } else {
                uf.unite(c0, c);
            }
        } else {
            outputStr.push_back(c);
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        if (cs.contains(c) && cs.contains(c - 32)) {
            uf.unite(c, c - 32);
        }
    }
    for (char& c : outputStr) {
        c = uf.find(c);
    }
    cout << outputStr << endl;
}