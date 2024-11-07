#include "../utils/abel_macro.h"

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> time;
    for (int i = 0; i < n; i++) {
        int p, q;
        cin >> p >> q;
        time.emplace_back(p, p + q);
    }
    ranges::sort(time, [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    int stop = time[0].second, cnt = 1;
    for (auto& [p, q] : time) {
        if (p - stop >= 15) {
            cnt++;
            stop = q;
        }
    }
    cout << cnt << endl;
}