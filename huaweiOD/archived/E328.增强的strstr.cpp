#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    string src, tar;
    getline(cin, src);
    getline(cin, tar);

    vector<unordered_set<char>> bracks;
    vector<int> brackEnd;
    bool inBrack;
    for (int i = 0; i < tar.length(); ++i) {
        char c = tar[i];
        if (c == '[') {
            bracks.emplace_back();
            inBrack = true;
        } else if (c == ']') {
            inBrack = false;
            brackEnd.push_back(i);
        } else if (inBrack) {
            bracks.back().insert(c);
        }
    }
    // for (auto brack : bracks) {
    //     for (auto c : brack) {
    //         cout << c << " ";
    //     }
    //     cout << endl;
    // }
    int idx = 0, matchIdx = 0;
    for (int i = 0, j = 0; i < src.length() && j < tar.length(); ++i) {
        if (tar[j] == '[') {
            ++j;
            inBrack = true;
        }
        if (inBrack) {
            if (bracks[idx].contains(src[i])) {
                j = brackEnd[idx] + 1; // fast forward to ]
                ++idx;
            } else {
                j = 0;
                idx = 0;
                matchIdx = i + 1;
            }
            inBrack = false;
        } else {
            if (src[i] == tar[j]) {
                ++j;
            } else {
                j = 0;
                idx = 0;
                matchIdx = i + 1;
            }
        }
    }
    cout << (matchIdx == tar.length() ? -1 : matchIdx)  << endl;
}