#include "../utils/abel_macro.h"

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> piles;
    int x;
    while (ss >> x) {
        piles.push_back(x);
    }
    int h;
    cin >> h;

    int n = piles.size();
    if (n == 0 || h <= 0 || n >= 10000 || h >= 10000 || n > h) {
        cout << 0 << endl;
        return 0;
    }

    auto check = [&](int k) -> bool {
        int sum = n;
        for (int p : piles) {
            sum += (p - 1) / k;
            if (sum > h) return false;
        }
        return true;
    };

    int left = 0, right = ranges::max(piles);
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        (check(mid) ? right : left) = mid;
    }
    cout << right << endl;
}