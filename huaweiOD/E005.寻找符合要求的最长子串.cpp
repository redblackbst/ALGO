#include "../utils/abel_macro.h"

int main() {
    string fb, s;
    cin >> fb >> s;
    char fc = fb[0]; // forbidden char
    unordered_map<char, int> cnt;
    int ans = 0;
    for (int left = 0, right = 0; right < s.length(); right++) {
        if (s[right] == fc) {
            left = right + 1;
        }
        cnt[s[right]]++;
        while (cnt[s[right]] > 2) {
            cnt[s[left++]]--;
        }
        ans = max(ans, right - left + 1);
    }
    cout << ans << endl;
}