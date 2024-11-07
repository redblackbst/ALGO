#include "../utils/abel_macro.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> f(amount + 1, INT_MAX / 2);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                f[j] = min(f[j], f[j-coins[i]] + 1);
            }
        }
        int ans = f[amount];
        return ans < INT_MAX / 2 ? ans : -1;
    }
};

int main() {
    Solution a;
    // vector<int> coins{1,2,5}; int M = 11;
    vector<int> coins{2}; int M = 3;
    cout << a.coinChange(coins, M) << endl;
}