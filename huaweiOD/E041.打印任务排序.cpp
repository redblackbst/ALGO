#include "../utils/abel_macro.h"

int main() {
    // string line;
    // getline(cin, line);
    // stringstream ss(line);
    vector<pair<int, int>> tasks;
    char ignore;
    for (int i = 0, x; cin >> x; i++) {
        tasks.emplace_back(i, x);
        cin >> ignore;
    }
    ranges::stable_sort(tasks, [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });
    for (const auto& [i, p] : tasks) {
        cout << i << ",";
    }
}