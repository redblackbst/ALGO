#include "../utils/abel_macro.h"

int main() {
    vector<int> st(1000);
    int x, sz = 0;
    while (cin >> x) {
        int sum = x;
        for (int i = sz - 1; i >= 0; i--) {
            sum -= st[i];
            if (sum == 0) {
                sz = i;
                x *= 2;
                sum = x;
            } else if (sum < 0) {
                break;
            }
        }
        st[sz++] = x;
    }
    for (int i = sz - 1; i >= 0; i--) {
        cout << st[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
}