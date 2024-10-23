#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s0;
    cin >> s0;
    string s1 = s0;
    sort(s1.begin(), s1.end());

    int n = s1.length();
    if (s0 != s1) {
        for (int i = 0; i < n; ++i) {
            if (s0[i] != s1[i]) {
                int k = -1;
                char c = s1[i];
                for (int j = i + 1; j < n; ++j) {
                    if (s0[j] == c) {
                        k = j;
                    }
                }
                swap(s0[i], s0[k]);
                break;
            }
        }
    }
    cout << s0 << endl;
}