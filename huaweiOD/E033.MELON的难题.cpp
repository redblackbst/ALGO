#include "../utils/abel_macro.h"

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int sum = reduce(nums.begin(), nums.end());
    if (sum % 2) {
        cout << -1 << endl;
        return 0;
    }
    sum /= 2;
    vector<int> f(sum + 1, INT_MAX / 2);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        int w = nums[i];
        for (int j = sum; j >= w; j--) {
            f[j] = min(f[j], f[j-w] + 1);
        }
    }
    cout << (f[sum] < INT_MAX / 2 ? f[sum] : -1) << endl;
}