#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k;
    cin >> k;
    cin.ignore();
    string ss;
    vector<string> sa;
    while (getline(cin, ss, '-')) {
        sa.push_back(ss);
    }

    string s1 = sa[0], s2 = "";
    for (int i = 1; i < sa.size(); ++i) {
        s2 += sa[i];
    }
    sa.clear();
    int i = 0;
    for (; i < s2.length(); i += k) {
        sa.push_back(s2.substr(i, k)); // past end of string OK
    }

    ss = s1;
    for (string& s : sa) {
        int up = count_if(s.begin(), s.end(), [](char c) { return isupper(c); });
        int lo = count_if(s.begin(), s.end(), [](char c) { return islower(c); });
        if (up > lo) {
            transform(s.begin(), s.end(), s.begin(), ::toupper);
        } else if (up < lo) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
        }
        ss += "-" + s;
    }
    cout << ss << endl;
}