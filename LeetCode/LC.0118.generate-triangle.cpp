#include "../utils/abel_macro.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                auto rowPre = ans.back();
                row[j] = rowPre[j-1] + rowPre[j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};

int main() {
    Solution a;
    int numRows = 5;
    auto ans = a.generate(numRows);
    cout << ans.size() << " " << ans[0].size() << endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}