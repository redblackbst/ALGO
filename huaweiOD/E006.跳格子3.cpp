#include "../utils/abel_macro.h"

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;
    if (n == 1) {
        cout << nums[0] << endl;
        return 0;
    }
    vector<int> f(n); // not n + 1?
    f[0] = nums[0];
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1; i < n; i++) {
        if (!dq.empty() && dq.front() < i - k) {
            dq.pop_front();
        }
        f[i] = (dq.empty() ? 0 : f[dq.front()]) + nums[i];
        while (!dq.empty() && f[dq.back()] <= f[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << f[n-1] << endl;
}