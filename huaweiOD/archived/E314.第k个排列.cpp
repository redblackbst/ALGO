#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> path(n), onPath(n);
    int cnt = 0;
    function<void(int)> dfs = [&](int i) {
        if (i == n) {
            cnt++;
            if (cnt == k) {
                for (int x : path) {
                    cout << x;
                }
                cout << endl;
            }
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!onPath[j]) {
                path[i] = j + 1;
                onPath[j] = true;
                dfs(i + 1);
                onPath[j] = false;
            }
        }
    };
    dfs(0);
}