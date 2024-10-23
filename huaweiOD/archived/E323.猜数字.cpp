#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string,string>> guessPair;
    for (int i = 0; i < n; ++i) {
        string num, hint;
        cin >> num >> hint;
        guessPair.push_back(make_pair(num, hint));
    }

    int cntValid = 0;
    string trueAns;
    for (int k = 0; k < 9999; ++k) {
        stringstream ss;
        ss << setw(4) << setfill('0') << k;
        string ans = ss.str();
        bool isValid = true;

        for (const auto& guess : guessPair) {
            string num = guess.first, hint = guess.second;
            int cnt1 = 0, cnt2 = 0;
            vector<int> guessCnt(10), ansCnt(10);

            for (int i = 0; i < num.length(); ++i) {
                if (num[i] == ans[i]) {
                    ++cnt1;
                } else {
                    guessCnt[num[i]-'0']++;
                    ansCnt[ans[i]-'0']++;
                }
            }

            for (int i = 0; i < 10; ++i) {
                cnt2 += min(guessCnt[i], ansCnt[i]);
            }

            if (hint[0] - '0' != cnt1 || hint[2] - '0' != cnt2) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            cntValid++;
            trueAns = ans;
            if (cntValid > 1) {
                break;
            }
        }
    }
    if (cntValid != 1) {
        cout << "NA" << endl;
    } else {
        cout << trueAns << endl;
    }
}