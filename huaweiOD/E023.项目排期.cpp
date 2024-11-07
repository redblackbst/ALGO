#include "../utils/abel_macro.h"

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> work;
    int x;
    while (ss >> x) {
        work.push_back(x);
    }
    int n = work.size(), k;
    cin >> k;

    vector<int> sum(1<<n);
    for (int i = 1; i < 1<<n; i++) {
        for (int j = 0; j < n; j++) {
            if (i>>j & 1) sum[i] += work[j];
        }
    }
    vector<int> f(sum);
    for (int i = 1; i < k; i++) {
        for (int j = (1<<n) - 1; j; j--) {
            for (int s = j; s; s = (s-1) & j) {
                f[j] = min(f[j], max(f[j^s], sum[s]));
            }
        }
    }
    cout << f.back() << endl;
}