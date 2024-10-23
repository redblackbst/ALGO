#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    vector<int> cnt;
    while (cin >> k) {
        cnt.push_back(k);
    }
    int sum = 0;
    for (auto x : cnt) {
        sum += x;
    }

    int n = cnt.size();
    vector<int> ans(n);
    int num = 1, idx = 0;
    while (sum) {
        if (num % 7 == 0 || to_string(num).find("7") != string::npos) {
            --sum;
            ++ans[idx];
        }
        idx = (idx + 1) % n;
        ++num;
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << ans[i] << " ";
    }
    cout << ans[n-1];
}