#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c, s, minVal;
    cin >> r >> c >> s >> minVal;
    vector<vector<int>> M(r, vector<int>(c));
    int ans = 0;
    for (int i = s; i < r; ++i) {
        for (int j = s; j < c; ++j) {
            int total = 0;
            for (int x = i - s; x < i; ++x) {
                for (int y = j - s; y < j; ++y) {
                    total += M[x][y];
                }
            }
            if (total >= minVal) ++ans;
        }
    }
    cout << ans << endl;
}