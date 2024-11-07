#include "../utils/abel_macro.h"

constexpr int MAPPING[10] = {0, 0, 5, 0, 0, 2, 9, 0, 0, 6};

int concatNum(const vector<int>& nums, int len) {
    string res = "";
    for (int i = 0; i < len; i++) {
        res += to_string(nums[i]);
    }
    return stoi(res);
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    unordered_set<int> numSet;
    vector<int> nums;
    int x, n = INT_MIN;
    while (ss >> x) {
        if (x < 1 || x > 9 || !numSet.insert(x).second) {
            cout << -1 << endl;
            return 0;
        }
        nums.push_back(x);
        n = max(n, x);
        ss.ignore();
    }
    if (numSet.size() != 4 || (numSet.contains(2) && numSet.contains(5)) || (numSet.contains(6) && numSet.contains(9))) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> res, path(4), onPath(10);
    function<void(int)> dfs = [&](int i) -> void {
        if (i > 0) {
            res.push_back(concatNum(path, i));
        }
        if (i == 4) {
            return;
        }
        for (int x : nums) {
            if (!onPath[x]) {
                path[i] = x;
                onPath[x] = true;
                dfs(i + 1);
                int alt = MAPPING[x]; // use alternative number
                if (alt != 0 && !onPath[alt]) {
                    path[i] = alt;
                    dfs(i + 1);
                }
                onPath[x] = false;
            }
        }
    };
    dfs(0);
    if (res.empty()) {
        cout << -1 << endl;
        return 0;
    }
    ranges::sort(res);
    // for (int x : res) {
    //     cout << x << " ";
    // }
    // cout << endl;
    int k = min(n, (int) res.size());
    cout << res[k-1] << endl;
}