#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s1, s2;
    int k;
    getline(cin, s1);
    getline(cin, s2);
    cin >> k;

    vector<int> s1Cnt(26), cnt(26);
    for (char c : s1) {
        s1Cnt[c-'a']++;
    }

    int leftChars = s1.length();
    bool hasSubstr = false;
    for (int left = 0, right = 0; right < s2.length(); ++right) {
        char cr = s2[right];
        cnt[cr-'a']++;
        if (cnt[cr-'a'] <= s1Cnt[cr-'a']) {
            leftChars--;
        }
        if (right - left + 1 > s1.length() + k) {
            char cl = s2[left];
            if (cnt[cl-'a'] <= s1Cnt[cl-'a']) {
                leftChars++;
            }
            cnt[cl-'a']--;
            ++left;
        }
        if (leftChars == 0) {
            cout << left << endl;
            hasSubstr = true;
            break;
        }
    }
    if (!hasSubstr) cout << -1 << endl;
}