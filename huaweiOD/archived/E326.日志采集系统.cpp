#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    vector<int> log;
    while (cin >> k) {
        log.push_back(k);
    }
    int cnt = 0, maxScore = 0;
    for (int i = 0; i < log.size(); ++i) {
        cnt += log[i];
        int score = 0;
        for (int j = 0; j <= i; ++j) {
            if (cnt >= 100 && j == i) {
                score += 100 + log[i] - cnt;
            } else {
                score += log[j] - (i - j) * log[j];
            }
        }
        maxScore = max(maxScore, score);
        if (cnt >= 100) break;
    }
    cout << maxScore << endl;
}