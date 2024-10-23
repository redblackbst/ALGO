#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> power(n);
    for (int i = 0; i < n; ++i) {
        cin >> power[i];
    }

    int p_max;
    cin >> p_max;

    vector<int> dp(p_max + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = p_max; j >= power[i]; --j) {
            dp[j] = max(dp[j], dp[j-power[i]] + power[i]);
        }
    }
    cout << dp[p_max] << endl;
}