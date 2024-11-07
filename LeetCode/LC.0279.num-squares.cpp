#include "../utils/abel_macro.h"

const int N = 10000;
int f[N+1];

auto init = [] {
    ranges::fill(f, INT_MAX);
    f[0] = 0;
    for (int i = 1; i * i <= N; ++i) {
        for (int j = i * i; j <= N; ++j) {
            f[j] = min(f[j], f[j-i*i] + 1);
        }
    }
    return 0;
}();

class Solution {
public:
    int numSquares(int n) {
        return f[n];
    }
};

int main() {
    Solution a;
    int n = 12;
    cout << a.numSquares(n) << endl;
}