#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> storage(n);
    for (int i = 0; i < n; ++i) {
        cin >> storage[i];
    }
    vector<vector<int>> price(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> price[i][j];
        }
    }

    int mp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            mp += storage[i] * max(0, price[i][j] - price[i][j-1]);
        }
    }
    cout << mp << endl;
}