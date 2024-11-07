#include "../utils/abel_macro.h"

int main() {
    vector<int> time;
    int x;
    while (cin >> x) {
        time.push_back(x);
    }
    int maxTime = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int parent = q.front();
        q.pop();
        int left = 2 * parent + 1, right = 2 * parent + 2;
        if (left < time.size() && time[left] != -1) {
            time[left] += time[parent];
            q.push(left);
        }
        if (right < time.size() && time[right != -1]) {
            time[right] += time[parent];
            q.push(right);
        }
        maxTime = max({maxTime, time[left], time[right]});
    }
    cout << maxTime << endl;
}