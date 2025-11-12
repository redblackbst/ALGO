#include "../utils/abel_macro.h"

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        int start = rounds[0], end = rounds.back();
        if (start <= end) {
            for (int i = start; i <= end; i++) {
                res.push_back(i);
            }
        } else {
            for (int i = 1; i <= end; i++) {
                res.push_back(i);
            }
            for (int i = start; i <= n; i++) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    auto a = Solution();
    int n = 4;
    vector<int> rounds{1,3,1,2};
    auto res = a.mostVisited(n, rounds);
    cout << res << endl;
}