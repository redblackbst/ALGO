#include "../utils/abel_macro.h"

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1);
        for (auto& op : shifts) {
            int start = op[0], end = op[1], dir = 2 * op[2] - 1;
            diff[start] += dir;
            diff[end+1] -= dir;
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            c += diff[i];
            // shift could be negative
            s[i] = 'a' + ((s[i] - 'a' + c) % 26 + 26) % 26;
        }
        return s;
    }
};

int main() {
    auto a = Solution();
    string s = "abc";
    vector<vector<int>> shifts = {{0,1,0},{1,2,1},{0,2,1}};
    string t = a.shiftingLetters(s, shifts);
    cout << t << endl;
}