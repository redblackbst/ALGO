#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string tmp;
    getline(cin, tmp);
    tmp = tmp.substr(1, tmp.length()-2);
    istringstream iss(tmp);
    vector<int> steps;
    while (getline(iss, tmp, ',')) {
        steps.push_back(stoi(tmp));
    }

    int target;
    cin >> target;
    int sum = INT_MAX, n = steps.size();
    // string ans = "";

    // for (int i = 0; i < n; ++i) {
    //     for (int j = i+1; j < n; ++j) {
    //         int a = steps[i], b = steps[j];
    //         if (a + b == target && i + j < sum) {
    //             sum = i + j;
    //             ans = "[" + to_string(a) + "," + to_string(b) + "]";
    //             break;
    //         }
    //     }
    // }
    // cout << ans << endl;

    unordered_map<int, int> numToIdx;
    for (int i = 0; i < n; i++) {
        int other = target - steps[i];
        if (numToIdx.contains(other)) {
            cout << '[' << other << ',' << steps[i] << ']' << endl;
            return 0;
        }
        numToIdx[other] = i;
    }
}