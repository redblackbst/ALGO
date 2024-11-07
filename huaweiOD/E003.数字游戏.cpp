#include "../utils/abel_macro.h"

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int n, m;
        ss >> n >> m;
        vector<int> nums(n);
        getline(cin, line);
        ss.str(line);
        ss.clear();
        for (int i = 0; i < n; i++) {
            ss >> nums[i];
        }

        unordered_set<int> vis;
        int rem = 0;
        bool found = false;
        for (int x : nums) {
            rem = (rem + x) % m;
            if (vis.contains(rem)) {
                found = true;
                break;
            };
            vis.insert(rem);
        }
        cout << (found ? 1 : 0) << endl;
    }
}