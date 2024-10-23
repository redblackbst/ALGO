#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool canReceiveAward(const vector<string>& rec) {
    int cnt1 = 0, cnt2 = 0, n = rec.size();
    for (int i = 0; i < n; ++i) {
        if (rec[i] == "absent") {
            ++cnt1;
            if (cnt1 > 1) return false;
        }
        if (rec[i] == "late" || rec[i] == "leaveearly") {
            if (i > 0 && (rec[i-1] == "late" || rec[i-1] == "leaveearly"))
                return false;
        }
        if (rec[i] != "present") ++cnt2;
        if (i < 6) continue;
        if (cnt2 > 3) return false;
        if (rec[i-6] != "present") --cnt2;
    }
    return true;
}

int main() {
    int ncase;
    cin >> ncase;
    cin.ignore();
    for (int k = 0; k < ncase; ++k) {
        string str, s;
        getline(cin, str);
        istringstream iss(str);
        vector<string> records;
        while (iss >> s) {
            records.push_back(s);
        }
        cout << (canReceiveAward(records) ? "true" : "false") << " ";
    }
    cout << endl;
}