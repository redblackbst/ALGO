#include "../utils/abel_macro.h"

int main() {
    int n;
    cin >> n;
    unordered_map<string, unordered_set<string>> tree;
    for (int i = 0; i < n; i++) {
        string child, parent;
        cin >> child >> parent;
        tree[parent].insert(child);
    }
    string tar;
    cin >> tar;
    if (!tree.contains(tar)) {
        cout << endl;
        return 0;
    }
    queue<string> q(tree[tar].begin(), tree[tar].end());
    set<string> res;
    while (!q.empty()) {
        string x = q.front(); q.pop();
        res.insert(x);
        if (tree.contains(x)) {
            for (const string& y : tree[x]) {
                q.push(y);
            }
        }
    }
    for (const string& x : res) {
        cout << x << endl;
    }
}