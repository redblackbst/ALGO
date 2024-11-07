#include "../utils/abel_macro.h"

int main() {
    int N, K;
    cin >> N >> K;
    cin.ignore();
    vector<queue<int>> qList;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        queue<int> q;
        int x;
        while (ss >> x) q.push(x);
        qList.push_back(q);
    }
    vector<vector<int>> wList(N);
    for (int k = 0, qIndex = -1, n = N * K; k < n; k++) {
        int wIndex = k % N;
        if (wIndex == 0) {
            qIndex = (qIndex + 1) % qList.size();
        }
        while (qList[qIndex].empty()) {
            qIndex = (qIndex + 1) % qList.size();
        }
        wList[wIndex].push_back(qList[qIndex].front());
        qList[qIndex].pop();
    }
    for (const auto& w : wList) {
        for (int x : w) {
            cout << x << " ";
        }
        cout << endl;
    }
}