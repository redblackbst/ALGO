#include "../utils/abel_macro.h"

int main() {
    int m;
    cin >> m;
    vector<int> vals;
    int val;
    while (cin >> val) {
        vals.push_back(val);
    }
    vector<int> f(m + 1);
    for (int i = 0; i < vals.size(); i++) {
        for (int j = i + 1; j <= m; j++) {
            f[j] = max(f[j], f[j-(i+1)] + vals[i]);
        }
    }
    cout << f[m] << endl;
}