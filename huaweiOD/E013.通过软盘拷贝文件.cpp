#include "../utils/abel_macro.h"

int main() {
    int n;
    cin >> n;
    vector<int> sz(n);
    for (int i = 0; i < n; i++) {
        cin >> sz[i];
    }
    int blk = 1474560 / 512;
    vector<int> f(blk + 1);
    for (int i = 0; i < n; i++) {
        int weight = ceil(sz[i] / 512.0);
        int val = sz[i];
        for (int j = blk; j >= weight; j--) {
            f[j] = max(f[j], f[j-weight] + val);
        }
    }
    cout << f[blk] << endl;
}