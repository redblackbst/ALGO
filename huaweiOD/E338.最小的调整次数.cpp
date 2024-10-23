#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    queue<int> q;
    bool inOrder = true;
    int cnt = 0;
    for (int i = 0; i < 2 * N; ++i) {
        string line, op, tmp;
        int k;
        getline(cin, line);
        stringstream ss(line);
        ss >> op >> tmp >> k;
        if (op == "head") {
            if (!q.empty()) inOrder = false;
            q.push(k);
        } else if (op == "tail") {
            q.push(k);
        } else {
            if (q.empty()) continue;
            if (!inOrder) {
                ++cnt;
                inOrder = true;
            }
            q.pop();
        }
    }
    cout << cnt << endl;
}