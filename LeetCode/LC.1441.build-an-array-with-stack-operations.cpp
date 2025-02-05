#include "../utils/abel_macro.h"

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int prev_t = 0;
        for (auto& t : target) {
            for (int k = prev_t + 1; k < t; k++) {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
            prev_t = t;
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> target{1,2};
    int n = 4;
    auto ans = a.buildArray(target, n);
    for (auto& s : ans) {
        cout << s << " ";
    }
}