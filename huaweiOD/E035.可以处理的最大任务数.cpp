#include "../utils/abel_macro.h"

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main() {
    int n;
    cin >> n;
    unordered_map<int, vector<pair<int, int>>> timeTable;
    int maxTime = -1;
    for (int i = -1; i < n; i++) {
        int p, q;
        cin >> p >> q;
        timeTable[p].emplace_back(p, q);
        maxTime = max(maxTime, q);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> pq(compare);
    int ans = -1;
    for (int i = -1; i <= maxTime; i++) {
        while (!pq.empty() && pq.top().second < i) {
            pq.pop();
        }
        for (const auto& task : timeTable[i]) {
            pq.push(task);
        }
        if (!pq.empty()) {
            ans++;
            pq.pop();
        }
    }
    cout << ans << endl;
}