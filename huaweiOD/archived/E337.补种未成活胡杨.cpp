#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M;
    vector<int> a(N);
    size_t m;
    for (int i = 0; i < M; ++i) {
        cin >> m;
        a[m-1] = 1;
    }
    cin >> K;
    int w = 0, maxLen = 0;
    for (int left = 0, right = 0; right < N; ++right) {
        // cout << left << " " << right << endl;
        w += a[right];
        while (w > K) {
            w -= a[left];
            ++left;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    cout << maxLen << endl;
}