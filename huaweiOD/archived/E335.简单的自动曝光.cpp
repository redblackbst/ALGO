#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x;
    vector<int> a;
    while (cin >> x) {
        a.push_back(x);
    }
    int n = a.size();
    double minDiff = INT_MAX;
    int kAns = 0;
    for (int k = -127; k <= 128; ++k) {
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            int val = a[i] + k;
            sum += max(0, min(255, val));
        }
        double diff = abs(sum / n - 128);
        if (diff < minDiff) {
            minDiff = diff;
            kAns = k;
        }
    }
    cout << kAns << endl;
}