#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> M(r, vector<int>(c));
    unordered_map<int,vector<pair<int,int>>> map;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> M[i][j];
            map[M[i][j]].emplace_back(i, j);
        }
    }
    vector<vector<int>> res(r, vector<int>(c, -1));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int k = M[i][j];
            int minDist = INT_MAX;
            if (map[k].size() > 1) {
                for (const auto& pos : map[k]) {
                    int x = pos.first, y = pos.second;
                    if (x != i || y != j) {
                        int dist = abs(x - i) + abs(y - j);
                        minDist = min(minDist, dist);
                    }
                }
                res[i][j] = minDist;
            }
        }
    }
    cout << "[";
    for (int i = 0; i < r; ++i) {
        cout << "[";
        for (int j = 0; j < c; ++j) {
            cout << res[i][j];
            if (j != c - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != r - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}