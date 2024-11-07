#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> cnt(26);
        for (char c : s) cnt[c-'a']++;
        vector<int> nxt(26);
        for (int i = 1; i <= t; ++i) {
            nxt.clear();
            for (int j = 0; j < 25; ++j) {
                nxt[j+1] = cnt[j];
            }
            nxt[0] = cnt[25];
            nxt[1] = (cnt[0] + cnt[25]) % MOD;
            for (int j = 0; j < 26; ++j) {
                cnt[j] = nxt[j];
            }
        }
        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % MOD;
        }
        return ans;
    }
};

int main() {
    Solution a;
    // string s = "abcyy";
    // int t = 2;
    string s = "jqktcurgdvlibczdsvnsg";
    int t = 7517;
    // string s = "azbk";
    // int t = 1;
    cout << a.lengthAfterTransformations(s, t);
}