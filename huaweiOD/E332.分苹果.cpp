#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int xorSum = 0, minWeight = INT_MAX;
    for (int x : a) {
        xorSum ^= x;
        if (x < minWeight) {
            minWeight = x;
        }
    }
    if (xorSum != 0) {
        cout << -1 << endl;
    } else {
        cout << accumulate(a.begin(), a.end(), 0) - minWeight << endl;
    }
}