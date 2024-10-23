#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> time(n, INT_MAX);
    queue<pair<int,int>> q;

    for (int i = 0; i < m; ++i) {
        int t, p;
        cin >> t >> p;
        time[p] = t;
        q.push({p, t});
    }
    while (!q.empty()) {
        int t = q.front().second, p = q.front().first;
        q.pop();
        int nb[2] = {(p+n-1)%n, (p+1)%n};
        for (int x : nb) {
            if (time[x] > t + 1) {
                time[x] = t + 1;
                q.push({x, t+1});
            }
        }
    }
    int maxT = 0;
    vector<int> lastidx;
    for (int i = 0; i < n; ++i) {
        if (time[i] > maxT) {
            maxT = time[i];
            lastidx.clear();
            lastidx.push_back(i);
        } else if (time[i] == maxT) {
            lastidx.push_back(i);
        }
    }
    cout << lastidx.size() << endl;
    sort(lastidx.begin(), lastidx.end());
    for (int idx : lastidx) {
        cout << idx << " ";
    }
    cout << endl;
}