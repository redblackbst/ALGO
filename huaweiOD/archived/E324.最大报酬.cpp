#include <iostream>
#include <vector>
using namespace std;

int main() {
    int time, n;
    cin >> time >> n;
    vector<int> T(n), V(n);
    for (int i = 0; i < n; ++i) {
        cin >> T[i] >> V[i];
    }
    vector<int> f(time + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = time; j >= 1; --j) {
            if (j >= T[i]) {
                f[j] = max(f[j], f[j-T[i]] + V[i]);
            }
        }
    }
    cout << f[time] << endl;
}